#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


long long a[200500];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    a[n] = 1000000000;

    int l = 0, r = n;

    while(r>=l+40)
    {
        int mid1 = (l*2+r)/3;
        int mid2 = (l+r*2)/3;

        long long res1 = 0;
        long long res2 = 0;

        for(int i = 0; i<n; i++)
        {
            res1+=a[i]/a[mid1];
            res2+=a[i]/a[mid2];
        }
        res1*=a[mid1];
        res2*=a[mid2];

        if(res1>res2)
            r = mid2;
        else
            l = mid1;
    }
    long long maxRes = 0;
    for(int j = l; j<=r; j++)
    {
        long long rs = 0;
        for(int i = 0; i<n; i++)
        {
            rs+=a[i]/a[j];
        }
        rs*=a[j];
        maxRes = max(maxRes,rs);
    }
    cout << maxRes;



    return 0;
}

