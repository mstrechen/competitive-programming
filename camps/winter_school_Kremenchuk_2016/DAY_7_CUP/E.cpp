#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void rec(int l, int r, vector<int> robots, vector<vector<int> > & pairs, vector<int> & res)
{
    cout << l << ' ' << r << endl;
    if(l==r)
    {
        res[l] = robots.front();
        return;
    }
    if(l==r-1)
    {
        res[l] = robots.front();
        res[r] = robots.back();
        return;
    }

    int mid = robots.size()/2;

    int minmask = 0;
    int minMaskAns = 2*1000*1000;
    for(int mask = (1<<robots.size()) - 1; mask>0; mask--)
    if(__builtin_popcount(mask)==mid)
    {
        int currAns = 0;
        for(int i = 0; i<robots.size(); i++)
            for(int j = i+1; j<robots.size(); j++)
                if( ((mask>>i)&1) != ((mask>>j)&1))
                    currAns+=pairs[robots[i]][robots[j]];

        if(currAns<minMaskAns)
        {
            minMaskAns = currAns;
            minmask = mask;
        }
    }
    vector<int> robotsL, robotsR;

    for(int i = 0; i<(int)robots.size(); i++)
    if((minmask>>i)&1)
    {
        robotsL.push_back(robots[i]);
    }
    else
    {
        robotsR.push_back(robots[i]);
    }

    rec(l, l+mid-1,robots, pairs, res);
    rec(l+mid, r, robots, pairs, res);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> robots(n, 0), res(n,0);
    for(int i = 0; i<n; i++)
        robots[i] = i;

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

    rec(0, n-1, robots, pairs, res);

    int ans = 0;

    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            ans+=pairs[i][j]*(j-i);

    cout << ans;
    return 0;
}

