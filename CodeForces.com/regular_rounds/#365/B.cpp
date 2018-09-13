#include<iostream>

using namespace std;

long long a[100500];
int used[100500];
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    int tmp;
    long long summ = 0, summOfUsed = 0;
    long long ans = 0;
    cin >> n >> k;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        summ+=a[i];
    }
    for(int i = 0; i<k; i++)
    {
        cin >> tmp;
        tmp--;
        ans+=2*(summ-a[tmp]-summOfUsed)*a[tmp];
        summOfUsed+=a[tmp];
        if(tmp==0)
        {
            ans-=2*(a[tmp]*a[n-1]+a[tmp]*a[tmp+1]);

        }
        else
        if(tmp==n-1)
        {
            ans-=2*(a[tmp]*a[0]+a[tmp]*a[tmp-1]);
        }
        else
        {
            ans-=2*(a[tmp]*a[tmp-1]+a[tmp]*a[tmp+1]);
        }
        used[tmp] = 1;

    }
    for(int i = 0; i<n-1; i++)
    {
        if(used[i]&&used[i+1])
            ans+=2*a[i]*a[i+1];
    }
    if(used[0]&&used[n-1])
    {
        ans+=2*a[0]*a[n-1];
    }
    ans/=2;

    for(int i = 0; i<n; i++)
    {
        ans+=a[(i+1)%n]*a[i];
    }
    cout << ans;
    return 0;
}
