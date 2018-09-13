#include<iostream>
#include<cmath>

using namespace std;


double vecMul(double _x,double _y,double x0,double y0,double x1,double y1)
{
    double a = _x-x0,
           b = _y-y0,
           c = x1-x0,
           d = y1-y0;
    return a*d-b*c;
}


struct multigon
{
    int _x[10500], _y[10500];
    int n;
    bool intersect(int x0, int y0, int x1, int y1, double DELTA)
    {
        int pos = 0, neg = 0, zer = 0;
        for(int i = 0; i<n; i++)
        {
            double tmp = vecMul(_x[i], _y[i], x0+DELTA, y0, x1+DELTA, y1);
            if(abs(tmp)<0.0000001)
                zer++;
            else
            if(tmp>0)
                pos++;
            else
                neg++;
        }
        cout << neg << ' ' << pos << ' ' << DELTA <<endl;
        if(neg*pos)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
} MUL;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    double  w,v, u, X;
    cin >> n >> w >> v >> u;
    X = w*v/u;
    for(int i = 0; i<n; i++)
    {
        cin >> MUL._x[i] >> MUL._y[i];
    }
    MUL.n = n;
    cin.precision(20);
    MUL.intersect(0,0,w,X,0);
    MUL.intersect(0,0,w,X,1);
    MUL.intersect(0,0,w,X,2);

    if(1)
    {
        double l = 0, r = 2000000000;
        while(l<r-0.0000001)
        {
            if(MUL.intersect(0,0,X,w,(l+r)*v/2))
            {
                l = (l+r)/2;
            }
            else
            {
                r = (l+r)/2;
            }
        }
        cout << fixed << w/u+l;
    }
    else
    {
        cout << fixed << w/u;
    }
    return 0;
}

