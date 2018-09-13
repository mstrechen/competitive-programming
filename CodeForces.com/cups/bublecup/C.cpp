#include<iostream>
#include<algorithm>

using namespace std;

long long a[100500];

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    sort(a,a+n);

    long long ans = 0;
    for(int i = 0; i<n; i++)
        ans+=a[i]*a[n-i-1];

    cout << ans%10007;


    return 0;
}
