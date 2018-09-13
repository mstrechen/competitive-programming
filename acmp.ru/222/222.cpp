#include<stdio.h>
#include<cmath>
#include<iomanip>
#include<algorithm>

using namespace std;

const int MAXN = 105;

const double PI = double(acos(-1));
const double PI2 = 2*PI;

const double EPS = double(1e-7);
const double EPS_CALC = double(1e-4);



inline double sqr(double a)
{
    return a*a;
}

struct arc
{
    double l,r;
    arc(double l = 0, double r = 0) : l(l), r(r){}
};

ostream & operator << (ostream & out, const arc & toWrite)
{
    out << toWrite.l << ' ' << toWrite.r;
    return out;
}

bool operator < (const arc & l, const arc & r)
{
    return l.l < r.l;
}

bool operator != (const arc & l, const arc & r)
{
    return (l.l!=r.l) || (l.r!=r.r);
}
bool operator == (const arc & l, const arc & r)
{
    return (l.l==r.l) && (l.r==r.r);
}

const arc NO_ANSWER = arc(0,0);
const arc ALL_IS_DENIED = arc(0,PI2 + EPS);



struct circle
{
    double r;
    double x,y;

    circle(double r = 0, double x = 0, double y = 0) : r(r), x(x), y(y){}

    arc fov(double X, double Y)
    {
        double dAngle = asin(r/sqrt(sqr(x-X) + sqr(y-Y))),
            res = atan2(x-X, y-Y);

        return arc(res-dAngle-EPS, res+dAngle+EPS);
    }


};

void read(circle & toRead)
{
    scanf("%lf%lf%lf", &toRead.x, &toRead.y, &toRead.r);
}


int main()
{
    int n;

    scanf("%d", &n);


    double x0, y0;
    scanf("%lf%lf", &x0, &y0);

    circle tmp;

    vector<arc> arcs(n);

    double minAllowed = -100500;

    for(int i = 0; i<n; i++)
    {
        read(tmp);

        arcs[i] = tmp.fov(x0, y0);
        minAllowed = max(minAllowed, arcs[i].r);
    }
    minAllowed-=PI2;

    sort(arcs.begin(), arcs.end());


    for(int i = 0; i<n; i++)
    {
        if(arcs[i].l - minAllowed > 0)
        {
            printf("NO");
            return 0;
        }
        minAllowed = max(arcs[i].r, minAllowed);
    }

    printf("YES");


    return 0;
}
