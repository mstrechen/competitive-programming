#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;


    vector<long double> values(20000);
    vector<long double> pos(n+1, 0), next(n+1, 0);
    pos[0] = 1;

    for(int t = 0; t<20000; t++)
    {
        next.assign(n+1, 0);
        for(int i = 0; i<=n; i++)
        {
            next[i]+=pos[i]*i/n;
        }
        for(int i = 0; i<n; i++)
        {
            next[i+1]+=pos[i]*(n-i)/n;
        }

        values[t] = next[n];

        next.swap(pos);
    }

    int k;
    cin >> k;


    while(k--)
    {
        int t;
        cin >> t;
        long double tt = (t-1e-7)/2000;

        cout << (lower_bound(values.begin(), values.end(), tt) - values.begin()) + 1 << '\n';
    }



    return 0;
}

