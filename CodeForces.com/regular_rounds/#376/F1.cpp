#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

const int MAXN = 2000005;

long long counts[MAXN], a[MAXN];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        counts[a[i]]++;
    }
    for(int i = 1; i<MAXN; i++)
        counts[i]+=counts[i-1];
    set<int> A(a, a+n);

    long long ans = 0;
    for(auto i:A)
    {
        int c = 0;
        long long summ = 0;

        for(int j = i; j<MAXN; j+=i)
        {
            c++;
            int j1 = min(j+i-1, MAXN-1);
            long long count = counts[j1] - counts[j-1];
            summ+=count*i*c;
        }

        ans = max(ans, summ);
    }
    cout << ans;

    return 0;
}
