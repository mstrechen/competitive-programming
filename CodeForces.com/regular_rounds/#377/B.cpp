#include<iostream>

using namespace std;

int a[1000];




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >>n >> k;
    for(int i = 0; i<n; i++)
        cin >> a[i];

    int ans = 0;

    for(int i = 1; i<n; i++)
    {
        if(a[i]+a[i-1]<k)
        {
            ans+=k-a[i]-a[i-1];
            a[i]+=k-a[i]-a[i-1];
        }
    }
    cout << ans << '\n';
    for(int i = 0; i<n; i++)
        cout << a[i] << ' ';
    return 0;
}
