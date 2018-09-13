#include<iostream>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    long long a[2016];

    int i, j, n;
    long long Fi, Fj;
    cin >> i >> Fi >> j >> Fj >> n;

    long long l, r;
    i+=1000;
    j+=1000;
    n+=1000;
    a[i] = Fi;

    for(l = -2e9 - 3, r= 2e9 +3;;)
    {
        long long mid = (l+r)/2;
        a[i+1] = mid;

        for(int _i = i+2; _i<=2000; _i++)
            a[_i] = a[_i-1]+a[_i-2];
        for(int _i = i-1;  _i>=0; _i--)
            a[_i] = a[_i+2]-a[_i+1];

        if(a[j]==Fj)
        {
            cout << a[n];
            break;
        }

        else
            if((a[j]>Fj)^(i<j))
                l = mid;
            else
                r = mid;
    }

    return 0;
}
