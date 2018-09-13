#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, p, k;

    cin >> n >> p >> k;

    k%=n;

    p--;

    pair<long long, long long> ans;

    if(p%2 == 0)
    {
        p += k;

        ans = {(p + k - 1 + n)%n + 1, (p + k + 1 + n)%n + 1};
    }
    else
    {
        p -= k;
        p+=2*n;
        p%=n;

        ans = {(p - k - 1 + 2*n)%n + 1, (p - k + 1 + 2*n)%n + 1};

    }

    if(ans.first>ans.second)
        swap(ans.first, ans.second);

    cout << ans.first << ' ' << ans.second;

    return 0;
}
