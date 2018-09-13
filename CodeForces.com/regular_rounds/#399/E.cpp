#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<bitset>

using namespace std;

map<pair<long long, int>, char> mem;



char spragueGrundy(int n, long long mask)
{
    if(n==0)
        return 0;
    if(mem.count({mask, n}))
        return mem[{mask,n}];

    long long maskOfConnected = 0;
    for(int i = 1; i<=n; i++)
        if(((mask>>i)&1)==0)
        {
            maskOfConnected |= 1LL << spragueGrundy(n-i, mask|(1LL<<i));
        }

    if(maskOfConnected == 0)
        return mem[{mask,n}] = 0;
    return mem[{mask,n}] = __builtin_ffsll(~maskOfConnected) - 1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i <= 60; i++){
        cout << i << ':' << (int)spragueGrundy(i, 0) << endl;
    }
    int n;
    cin >> n;

    char ans = 0;
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        ans^=spragueGrundy(x, 0);
    }


    if(ans)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
