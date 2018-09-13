#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(a) (int)(a).size()

inline bool compareWithDiffEps(double a, double b, bool (*compWithEps)(double, double, double)) {
    static const double min_eps = 1e-11;
    static const double max_eps = 1e-6;

    bool res1 = compWithEps(a, b, min_eps);
    bool res2 = compWithEps(a, b, max_eps);

    return res1;
}

inline bool equalsWithEps(double a, double b, double eps)
{
    return fabs(a - b) < eps;
}

inline bool lessWithEps(double a, double b, double eps)
{
    return a + eps < b;
}

inline bool lessOrEqualsWithEps(double a, double b, double eps)
{
    return a - eps < b;
}

inline bool greaterWithEps(double a, double b, double eps)
{
    return a - eps > b;
}

inline bool greaterOrEqualWithEps(double a, double b, double eps)
{
    return a + eps > b;
}

double sqr(double x)
{
	return x * x;
}

bool isEquals(double a, double b)
{
	return compareWithDiffEps(a, b, equalsWithEps);
}

bool isLess(double a, double b)
{
	return compareWithDiffEps(a, b, lessWithEps);
}

bool isLessOrEqual(double a, double b)
{
	return compareWithDiffEps(a, b, lessOrEqualsWithEps);
}

bool isGreater(double a, double b)
{
	return compareWithDiffEps(a, b, greaterWithEps);
}

bool isGreaterOrEqual(double a, double b)
{
	return compareWithDiffEps(a, b, greaterOrEqualWithEps);
}

const double minSolutionMargin = 1e-6 * 5;
const double g = 10.0;
const double inf = 1000000.0;

double L, h, l, d, jumpVX, jumpVY, throwVX, throwVY;

// x(t) = vx * t
// => t(x) = x / vx
// y(t) = vy * t - g * sqr(t) / 2
// y(x) = vy * x / vx - g * sqr(x / vx) / 2
// y(x) = - g / sqr(vx) / 2 * sqr(x) + (vy / vx) * x
double getY(double vx, double vy, double x)
{
	return - g / sqr(vx) / 2.0 * sqr(x) + (vy / vx) * x;
}

// y'(x) = - g / sqr(vx) * x + (vy / vx) = 0
// x0 = (vy / vx) * sqr(vx) / g
// x0 = (vy * vx) / g
double getPeekX(double vx, double vy)
{
	return vy * vx / g;
}

struct Interval
{
	double l, r;
	bool isValid;
	Interval() { l = +inf; r = -inf; isValid = false; }
	Interval(double _l, double _r) { l = _l; r = _r; isValid = true; }

	Interval intersect(const Interval &oth) const
	{
		if (!isValid || !oth.isValid)
			return Interval();

		Interval result = Interval(max(l, oth.l), min(r, oth.r));
		if (isLessOrEqual(result.r, result.l))
			return Interval();

		return result;
	}

	void substract(const Interval &oth, Interval &result1, Interval &result2) const
	{
		if (!isValid)
		{
			result1 = result2 = Interval();
			return;
		}

		if (!oth.isValid)
		{
			result1 = result2 = *this;
			return;
		}

		Interval r1, r2;
		r1 = Interval(-inf, oth.l);
		r2 = Interval(oth.r, +inf);

		result1 = this->intersect(r1);
		result2 = this->intersect(r2);
	}
};

struct Solution
{
	vector < Interval > intervals;

	bool empty()
	{
		return sz(intervals) == 0;
	}

	void add(const Interval &newInterval)
	{
		intervals.pb(newInterval);
	}

	Solution intersect(const Interval &newInterval) const
	{
		if (!newInterval.isValid)
			return Solution();

		Solution result;
		for (int i = 0; i < sz(intervals); i ++)
		{
			Interval t = intervals[i].intersect(newInterval);
			if (t.isValid)
			{
				result.add(t);
			}
		}
		return result;
	}

	Solution substract(const Interval &newInterval) const
	{
		if (!newInterval.isValid)
			return *this;

		Solution result;
		for (int i = 0; i < sz(intervals); i ++)
		{
			Interval t1, t2;
			intervals[i].substract(newInterval, t1, t2);
			if (t1.isValid)
			{
				result.add(t1);
			}
			if (t2.isValid)
			{
				result.add(t2);
			}
		}
		return result;
	}
};

Interval solveFuncIsGreater(double a, double b, double c, double bound)
{
	assert(isLess(a, 0));

	c -= bound;
	double disc = sqr(b) - 4 * a * c;
	if (isLess(disc, 0))
	{
		return Interval();
	}

	double l = (-b + sqrt(max(0.0, disc))) / (2 * a);
	double r = (-b - sqrt(max(0.0, disc))) / (2 * a);
	assert(isLessOrEqual(l, r));

	return Interval(l, r);
}

void getFuncCoefficients(double rockX, double &a, double &b, double &c)
{
	a = - g / 2.0 / sqr(jumpVX) - g / 2 / sqr(throwVX);
	b = jumpVY / jumpVX - throwVY / throwVX + g / sqr(throwVX) * rockX;
	c = - g / 2 / sqr(throwVX) * sqr(rockX) + throwVY / throwVX * rockX;
}

Solution restrictFuncIsGreater(Solution solution, double rockX, double boundY)
{
	double a, b, c;
	getFuncCoefficients(rockX, a, b, c);
	Interval segm = solveFuncIsGreater(a, b, c, boundY);
	return solution.intersect(segm);
}

Solution restrictFuncIsLess(Solution solution, double rockX, double boundY)
{
	double a, b, c;
	getFuncCoefficients(rockX, a, b, c);
	Interval segm = solveFuncIsGreater(a, b, c, boundY);
	return solution.substract(segm);
}

Solution restrictPeek(Solution solution)
{
	double peekX = getPeekX(throwVX, throwVY);
	double peekY = getY(throwVX, throwVY, peekX);

	double a = - g / 2 / sqr(jumpVX);
	double b = jumpVY / jumpVX;
	double c = 0;

	Interval segm1 = solveFuncIsGreater(a, b, c, h + d - peekY);
	Interval segm2 = Interval(L - peekX, L + l - peekX);
	Interval forbidden = segm1.intersect(segm2);

	return solution.substract(forbidden);
}

int main()
{


	scanf("%lf%lf%lf%lf", &L, &h, &l, &d);
	scanf("%lf%lf%lf%lf", &jumpVX, &jumpVY, &throwVX, &throwVY);

	Solution solution;
	solution.add(Interval(0, min(L, 2 * jumpVX * jumpVY / g)));

	solution = restrictFuncIsGreater(solution, L, h);
	solution = restrictFuncIsGreater(solution, L + l, h);
	solution = restrictFuncIsLess(solution, L, h + d);
	solution = restrictFuncIsLess(solution, L + l, h + d);
	solution = restrictPeek(solution);

	if (solution.empty())
	{
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < sz(solution.intervals); i ++)
	{
		Interval &t = solution.intervals[i];
		t.l /= jumpVX;
		t.r /= jumpVX;

		if (isLess(t.r - t.l, minSolutionMargin))
		{
			fprintf(stderr, "Solution interval too tiny. L = %.6lf, R = %.6lf\n", t.l, t.r);
			throw 42;
		}
	}

	printf("%.9lf\n", (solution.intervals[0].l + solution.intervals[0].r) / 2.0);
	return 0;
}
