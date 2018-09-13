#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const double PI = 3.1415926535897;
double sqr(double a)
{
    return a*a;
}

double makeFackinShit(double x0, double y0, double r0,
                                   double x, double y, double r)
{
    double c = sqrt(sqr(x0-x)+sqr(y0-y));
    r0 = min(sqrt(c*c-r*r), r0);

    if(r0<0.5)
        return 0;
    if(r0+r<=c)
        return 0;

    return acos((r0*r0+c*c-r*r)/(2*r0*c));
}

vector<pair<double,bool> > rad;

char _c = ' ';
int sign;
void readDouble(double & a)
{
    long long _a = 0;
    while((_c<'0'||_c>'9')&&_c!='-')
        _c = getchar();
    if(_c=='-')
    {
        sign = -1;
        _c = getchar();
    }
    else
        sign = 1;
     while(_c>='0'&&_c<='9')
     {
         _a*=10;
         _a+=_c-'0';
         _c = getchar();
     }

    a = _a*sign;


}

int main()
{
    rad.reserve(200000);
    long long x0, y0, v, T,s;
    double tmpX, tmpY,  tmpR;
    double tmp1, tmp2;
    int n;
    cin >> x0 >> y0 >> v >> T;
    s = v*T;
    cin >> n;
    double possibility = 0;
    for(int i = 0; i<n; i++)
    {
        readDouble(tmpX);
        readDouble(tmpY);
        readDouble(tmpR);
        if(sqrt(sqr(x0-tmpX)+sqr(y0-tmpY))<=tmpR)
        {
            cout << 1 << endl;
            return 0;
        }
        else
        {
            tmp1 =makeFackinShit(x0,y0,s, tmpX, tmpY, tmpR);
            if((tmpY-y0)==0)
                tmp2 = PI/2;
            else
                tmp2 = atan((tmpX-x0)/(tmpY-y0));
            if(tmpX-x0<=0)
                tmp2+=PI;
            if(tmp1>0.000001)
            {
                rad.push_back({tmp2-tmp1, 0});
                rad.push_back({tmp2+tmp1, 1});
            }
        }
    }
    sort(rad.begin(), rad.end());
    double l = rad[rad.size()-1].first;
        l-=2*PI;
    for(int i = 0; i<rad.size(); i++)
    {
        rad[i].first = max(rad[i].first, l);
    }
    int counter = 1;
    double f = rad[0].first;
    for(int i = 1; i<rad.size();i++)
    {
        if(counter==0)
            f = rad[i].first;

        if(rad[i].second)
            counter--;
        else
            counter++;

        if(counter==0)
        {
            possibility+=(rad[i].first-f)/(2*PI);
        }

    }
    cout.precision(10);
    cout << fixed << possibility;
    return 0;
}
