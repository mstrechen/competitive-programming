#include<iostream>

using namespace std;


const double eps = 1e-9;

double sqr(double x)
{
    return x*x;
}

double sOfTriangle(pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
    double aSide = sqrt(sqr(a.first-b.first)+sqr(a.second+b.second))
}

bool getAnsFor1(int x, int y, vector<pair<int,int>> xy)
{
    double s = sqrt(sqr(xy[0].first-xy[1].first)+sqr(xy[0].second-xy[1].second))*
               sqrt(sqr(xy[2].first-xy[1].first)+sqr(xy[2].second-xy[1].second))
    double s1 = 0;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int x, y;
    vector<pair<int,int>> xy(4,{0,0});

    for(int i = 0; i<n; i++)
    {
        cin >> x >> y;
        for(int j = 0; j<4; j++)
            cin >> xy.first >> xy.second;
    }

    return 0;
}
