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

    vector<int> robots(n, 0), res(n,0);
    for(int i = 0; i<n; i++)
        robots[i] = i;

    res = robots;

    vector<vector<int> > pairs(n, vector<int>(n,0));

    int m;
    cin >> m;

    for(int i = 0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        pairs[x-1][y-1] = 1;
        pairs[y-1][x-1] = 1;
    }

    int ans = 0;

    vector<vector<int> > pairs_copy(pairs.begin(), pairs.end());

    for(int _i = 0; _i<n; _i++)
    for(int k = 0; k<n; k++)
    for(int i = k+1; i<n; i++)
    for(int j = i+1; j<n; j++)
    if(pairs[res[k]][res[j]]&&(pairs[res[k]][res[i]]^pairs[res[i]][res[j]]))
    if(pairs[res[k]][res[i]])
    {
        swap(res[k], res[i]);
    }
    else
    {
        swap(res[i],res[j]);
    }

    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            ans+=pairs_copy[res[i]][res[j]]*(j-i);


    cout << ans;

    return 0;
}

