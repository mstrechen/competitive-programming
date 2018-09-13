#include<stdio.h>
#include<vector>
#include<numeric>
#include<cfloat>
#include<cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<pair<double, double> > a(n);

    for(int i = 0; i<n; i++)
    {
        scanf("%lf%lf", &a[i].first, &a[i].second);
    }

    double l = min(a[0].first, a[1].first);
    double r = max(a[0].first, a[1].first);

    while(l<r-1e-6)
    {

        double midL = l + (r-l)/3;
        double midR = l + (r-l)*2/3;
        long double midLsumm = 0, midRsumm = 0;
        for(int i = 2; i<n; i++)
        {
            midLsumm+=a[i].second*a[i].second + (a[i].first-midL)*(a[i].first-midL);
            midRsumm+=a[i].second*a[i].second + (a[i].first-midR)*(a[i].first-midR);
        }
        if(midLsumm<midRsumm)
            r = midR;
        else
            l = midL;

    }

    printf("%.7f", (float)(l+r)/2);

    return 0;
}
