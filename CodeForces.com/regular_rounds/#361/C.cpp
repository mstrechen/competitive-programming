#include<iostream>
#include<cmath>


using namespace std;

long long cubes[1000500];
long long getCount(long long a)
{
    long long answer = 0;
    long long n = cbrt(a);
    for(int i = 2; i<=n; i++)
    {
        answer+=a/cubes[i];
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    long long n;
    for(long long i = 1; i<=1000000; i++)
    {
        cubes[i] = i*i*i;
    }

    cin >> n;
    long long l = 8, r = 10000000000000000,tmp, mid;
    for(;l<r-1;)
    {
        mid = (l+r)/2;
        tmp = getCount(mid);
        if(tmp<n)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if(getCount(l)==n)
    {
        cout << l;
        return 0;
    }
    if(getCount(r)==n)
    {
        cout << r;
        return 0;
    }
    if(getCount(r=1)==n)
    {
        cout << r+1;
        return 0;
    }
    cout << -1;

    return 0;
}
