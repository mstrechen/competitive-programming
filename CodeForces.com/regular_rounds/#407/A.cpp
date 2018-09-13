#include<iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;

    long long ans = 0;

    cin >> n >> k;

    for(int i = 0; i<n; i++)
    {
        long long x;
        cin >> x;
        ans += (x-1)/k + 1;
    }
    ans = (ans-1)/2 + 1;

    cout << ans;

    return 0;
}
