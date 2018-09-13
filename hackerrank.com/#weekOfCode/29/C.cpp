#include<iostream>
#include<cmath>

using namespace std;

const double eps = 1e-8;
const double PI = acos(-1);
const double PIWithEps = PI + 1e-9;

struct calc
{

    static int  sqr(int a)
    {
        return a*a;
    }

    static int distSqr(const pair<int, int> & A, const pair<int, int> & B)
    {
        return sqr(A.first - B.first) + sqr(A.second - B.second);
    }
    static double dist(const pair<int, int> & A, const pair<int, int> & B)
    {
        return sqrt(sqr(A.first - B.first) + sqr(A.second - B.second));
    }

    static double angle(const pair<int, int> & Center, const pair<int, int> & A, const pair<int, int> & B)
    {
        double a = dist(A,B);
        double b = dist(Center, A);
        double c = dist(Center, B);

        return acos((c*c + b*b - a*a)/(2*b*c));
    }

    static bool isInsideASquare(const pair<int, int> & ToCheck, const pair<int, int> & A, const pair<int, int> & B)
    {
        if(A == ToCheck || B == ToCheck)
            return 1;
        return (angle(A, ToCheck, B)*4<=PIWithEps && angle(B, ToCheck, A)*4 <=PIWithEps);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int w, h;
    cin >> w >> h;

    pair<int, int> Circle, A, B;
    int r;
    cin >> Circle.first >> Circle.second >> r;
    cin >> A.first >> A.second >> B.first >> B.second;

    r*=r;

    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            if(calc::distSqr(Circle, {x,y}) <= r  ||
               calc::isInsideASquare({x,y}, A, B))
               cout << "#";
            else
                cout << '.';
        }

        cout << '\n';
    }

    return 0;
}
