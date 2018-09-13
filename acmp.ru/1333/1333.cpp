#include<iostream>
#include<vector>

using namespace std;


int main()
{
    int n;

    cin >> n;
    vector<double> a(n,0);

    cin >> a[0];

    double l = 0,r = 1000000000, mid;

    while(l<r-0.00001)
    {
        mid = (l+r)/2;
        a[1] = mid;
        bool flag = 1;
        for(int i = 2; i<n&&flag; i++)
        {
            a[i] = 2*a[i-1]-a[i-2]+2;
            if(a[i]<=0)
                flag = 0;

        }
        if(flag)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    a[1] = mid;
    for(int i = 2; i<n; i++)
    {
        a[i] = 2*a[i-1]-a[i-2]+2;

    }
    cout.precision(5);
    cout << (fixed) << a[n-1];


    return 0;
}
