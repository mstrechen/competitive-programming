#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<tuple>

using namespace std;

using Line = tuple<double, double, double>;
using Point = pair<double, double>;

namespace My
{
    double abs(double a)
    {
        return a>0?a:-a;
    }
}

Line operator ^ (const Point & a, const Point & b)
{
    double A = 1;
    double B = (a.first - b.first)*1.0/(b.second - a.second);
    if(My::abs(b.second - a.second) < 1e-8)
    {
        A = 0;
        B = 1;
    }
    double C = -(A*a.first + B*a.second);

    return Line(A,B,C);
}

double operator - (const Point & a, const Line & l)
{
    double A,B,C;
    tie(A,B,C) = l;
    return My::abs(A * a.first + B * a.second + C)/sqrt(A*A + B*B);
}

istream & operator >> (istream & in, Point & toRead)
{
    in >> toRead.first >> toRead.second;
    return in;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> P(n);
    for(int i = 0; i<n; i++)
        cin >> P[i];

    double ans = 1e10;
    for(int i = 0; i<n; i++)
                ans = min(ans, P[(i+1)%n] - (P[i]^P[(i+2)%n]));

    cout.precision(10);
    cout << (fixed) << ans/2;
    return 0;
}
