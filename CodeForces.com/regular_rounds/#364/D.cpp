#include<iostream>
#include<iomanip>

using namespace std;

double getTimeTo(double l, double a,double currentPoint, int v1, int v2)
{
    return l>currentPoint+a?a/v2:(l-currentPoint)/v2;
}

double abs(double a)
{
    return a>0?a:-a;
}

double calc(double l, double a, int v1, int v2, int n)
{
    double res = 0;
    double currentPoint = 0, prevPoint, t;
    for(int i = 0; i<n; i++)
    {
        t = getTimeTo(l, a, currentPoint, v1, v2);
        res+=t;
        prevPoint = currentPoint;
        currentPoint+=t*v1;
        if(i!=n-1)
        {
            res+=(min(l, prevPoint+a)-currentPoint)/(v1+v2);
            currentPoint+=(min(l, prevPoint+a)-currentPoint)*v1/(v1+v2);
        }
        else
            res+=max(0.0,l-prevPoint-a)/v1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, v1,v2, k;
    double L;
    cin >> n >> L >> v1 >> v2 >> k;
    n = (n-1)/k+1;

    double tL, tR;
    double l = 0, r = L;
    while(l<r-0.1)
    {
        if(abs(calc(L,(l+r)/2, v1, v2, n)-L/v1)<0.00001)
        {
            r = (l+r)/2;
        }
        else
        {
            l = (l+r)/2;
        }
    }
    l = 0;
    while(l<r-0.0000001)
    {
        tL = calc(L,(2*l+r)/3, v1, v2, n);
        tR = calc(L,(l+r*2)/3, v1, v2, n);
        if(tL<tR)
            r = (l+r*2)/3;
        else
            l = (l*2+r)/3;
    }
    cout.precision(10);
    cout << (fixed) << min(L/v1, tL);
    return 0;
}

