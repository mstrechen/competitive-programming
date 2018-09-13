#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

pair<double, int> a[100000];
pair<double, int> b[100000];

long long sqr(long long a)
{
    return a*a;
}


int main(){
	ios::sync_with_stdio(false);
    int n;
    int x1,x2,y1,y2,x0,y0;
    int k, l;
    long long tmpX, tmpY;
    double allWay=0, tmpWay, minWay;
    cin >> x1 >> y1 >> x2 >> y2 >> x0 >> y0;
	cin >> n;
	for(int i = 0; i<n; i++)
    {
        cin >> tmpX >> tmpY;
        allWay+=sqrt(sqr(tmpX-x0) + sqr(tmpY-y0));
        a[i] = {sqrt(sqr(tmpX-x1) + sqr(tmpY-y1))-sqrt(sqr(tmpX-x0) + sqr(tmpY-y0)),i};
        b[i] = {sqrt(sqr(tmpX-x2) + sqr(tmpY-y2))-sqrt(sqr(tmpX-x0) + sqr(tmpY-y0)),i};
    }
    cout.precision(15);
    cout << fixed;
    allWay*=2;
    if(n==1)
        cout << min(allWay+a[0].first, allWay+b[0].first);
    else
    {
        sort(a,a+n);
        sort(b,b+n);
        minWay = allWay+a[0].first;
        minWay = min(minWay, allWay+b[0].first);
        for(int i = 0; i<n; i++)
        {
            if(a[i].second!=b[0].second)
            {
                minWay = min(minWay, allWay+b[0].first+a[i].first);
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(a[i].second!=b[1].second)
            {
                minWay = min(minWay, allWay+b[1].first+a[i].first);
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(a[0].second!=b[i].second)
            {
                minWay = min(minWay, allWay+b[i].first+a[0].first);
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(a[1].second!=b[i].second)
            {
                minWay = min(minWay, allWay+b[i].first+a[1].first);
            }
        }
        cout << minWay;
    }

	return 0;
}
