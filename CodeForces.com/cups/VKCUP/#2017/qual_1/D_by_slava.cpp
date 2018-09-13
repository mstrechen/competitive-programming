#include <bits/stdc++.h>

using namespace std;

const int MAXNUM = 1e4 + 1;

long long ans = 0;
int cnt[MAXNUM], x, n, k, kol = 0;
int v[(1 << 14)];

int main()
{
    freopen("D_2.txt", "r", stdin);
    freopen("D_2_ansS.txt", "w", stdout);

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        ++cnt[x];
    }

    for (int mask = 0; mask < (1 << 14); ++mask)
        if (__builtin_popcount(mask) == k)
        {
            v[kol] = mask;
            ++kol;
        }

    for (int i = 0; i < MAXNUM; ++i)
    {
        if (k == 0)
        {
            ans += cnt[i] * 1LL * (cnt[i] - 1) / 2;
            continue;
        }
        if (cnt[i])
        for (int q = 0; q < kol; ++q)
            if ((v[q] ^ i) <= i) ans += cnt[i] * 1LL * cnt[v[q] ^ i];
    }

    cout << ans;

    return 0;
}
