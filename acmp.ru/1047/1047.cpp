#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int oo = 2*1000*1000*1000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int> > cost(n, vector<int>(n) );

    for(auto & i : cost)
        for(auto & j : i)
            cin >> j;

    vector<int> perm(n);
    for(int i = 0; i<n; i++)
        perm[i] = i;

    int mincost = +oo;

    do
    {
        int currentcost = 0;
        for(int i = 0; i<n; i++)
            currentcost+=cost[perm[i]][i];

        mincost = min(mincost, currentcost);
    }
    while(next_permutation(perm.begin(), perm.end()));

    cout << mincost;

    return 0;
}
