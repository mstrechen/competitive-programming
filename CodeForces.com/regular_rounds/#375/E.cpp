#include<iostream>
#include<numeric>
#include<set>
#include<vector>

using namespace std;

void makeRaid(int _i, vector<set<int> > & g, vector<int> & twoness)
{
    while(g[_i].size())
    {
        int newI = -1;
        newI = *g[_i].begin();
        for(auto it = g[_i].begin(); it!=g[_i].end(); it++)
        {
            if(!twoness[*it])
            {
                newI = *it;
                break;
            }
        }
        g[_i].erase(newI);
        g[newI].erase(_i);
        cout << _i+1 << ' '<<newI+1 << '\n';
        _i = newI;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    vector<set<int> > g;
    vector<int> twoness;
    for(;t;t--)
    {
        int n, m;
        int x,y;
        cin >> n >> m;
        twoness.clear();
        g.clear();
        g.assign(n,set<int>());
        twoness.assign(n,0);
        for(int i = 0; i<m; i++)
        {
            cin >> x >> y;
            x--;
            y--;
            twoness[x]^=1;
            twoness[y]^=1;
            g[x].insert(y);
            g[y].insert(x);
        }
        bool flag  = 1;
        int currentDo = 0;
        cout << n-accumulate(twoness.begin(),twoness.end(),0) << '\n';
        while(flag)
        {
            flag = 0;
            for(int i = 0; (!flag)&&i<n; i++)
            {
                if(twoness[i]&&g[i].size())
                {
                    flag = 1;
                    currentDo = i;
                }
            }
            if(flag)
            {
                makeRaid(currentDo, g, twoness);
            }
            else
            {
                for(int i = 0; i<n; i++)
                {
                    if(g[i].size())
                    {
                        flag = 1;
                        makeRaid(i, g,twoness);
                    }
                }
            }
        }
    }

    return 0;
}
