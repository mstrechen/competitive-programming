#include<iostream>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    n = __builtin_popcount(n);
    int ans = 1;

    for(int i = 0; i<n; i++)
        ans*=4;

    cout << ans;

    return 0;
}
