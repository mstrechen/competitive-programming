#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cassert>
#include<bitset>

using namespace std;

long long oo = 1000000000LL*1000000000LL;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int len, width, n, m;

    cin >> len >> width >> n >> m;

    vector<int> A(n), B(m);
    vector<long long>dpPrev,dpCur;
    vector<pair<bitset<20500>,bitset<20500>> > ways(n+1, make_pair(bitset<20500>(0), bitset<20500>(0)));


    dpCur.assign(m+1, +oo);
    dpPrev = dpCur;
    dpCur[0] = 0;

    for(auto & i : A)
        cin >> i;
    for(auto & i : B)
        cin >> i;


    for(int i = 1; i<=n; i++)
    {
        dpPrev.swap(dpCur);
        dpCur[0] = +oo;

        for(int j = 1; j<=m; j++)
        {
            dpCur[j] = min(dpCur[j-1],
                       min(dpPrev[j],
                           dpPrev[j-1])) +  abs(A[i-1]-B[j-1]);
        }
        for(int j = 1; j<=m; j++)
        {
            long long val = dpCur[j] - abs(A[i-1]-B[j-1]);
            if(val == dpPrev[j-1])
            {
                ways[i].first[j] = 1;
                ways[i].second[j] = 1;
            }
            else
            if(val == dpPrev[j])
            {
                ways[i].first[j] = 0;
                ways[i].second[j] = 1;
            }
            else
            {
                ways[i].first[j] = 1;
                ways[i].second[j] = 0;
            }
        }
    }


    int cur_i = n, cur_j = m;

    vector<pair<int,int> > ans;
    do
    {
        ans.push_back({cur_i, cur_j});

        int alt_i = cur_i, alt_j = cur_j;

        cur_j-=ways[alt_i].first[alt_j];
        cur_i-=ways[alt_i].second[alt_j];

    }
    while(cur_i!=0&&cur_j!=0);


    cout << ans.size() << '\n';
    for(auto i : ans)
        cout << i.first << ' ' << i.second << '\n';



    return 0;
}
