#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int> > e(n);
    vector<int> dist(n,0);

    for(int i = 1; i<n; i++)
    {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }

    map<int, vector<int> > cur,next;
    for(int i = 0; i<n; i++)
        if(e[i].size() == 1)
            cur[i].push_back(i);

    bool flag = 1;
    bool blocked = 0;
    while(flag)
    {
        if(blocked)
        {
            cout << -1;
            return 0;
        }
        next.clear();
        for(auto & i : cur)
            dist[i.first] = dist[i.second.front()] + 1;

        for(auto & i : cur)
        {
            int val = 0;
            for(auto j : i.second)
            {
                if(val == 0)
                    val = dist[j];
                else
                if(val != dist[j])
                {
                    cout << -1;
                    return 0;
                }
            }
        }

        flag = 0;
        for(auto & i : cur)
        {
            int val = 0;
            bool curFlag = 0;
            for(auto v : e[i.first])
                if(dist[v] == 0)
                {
                    next[v].push_back(i.first);
                    flag = 1;
                    curFlag = 1;
                }
            if(curFlag == 0)
                blocked = 1;


        }
        next.swap(cur);
    }

    vector<int> finlist;
    for(auto & i : next)
    {
        finlist.push_back(i.first);
    }
    set<int> used(finlist.begin(), finlist.end());

    int maxFound = 0;
    for(auto i : finlist)
    {
        int curcnt = 0;
        for(auto v : e[i])
            curcnt+=used.count(v);
        maxFound = max(maxFound, curcnt);
    }

    if( !(maxFound == 0 || maxFound == (int)finlist.size() - 1))
    {
        cout << -1;
        return 0;
    }


    if(next.size() == 1 || (maxFound == 0))
    {
        int d = dist[next.begin()->first];
        d--;
        while(d%2==0)
            d/=2;
        cout << d;
    }
    else
    {
        int d = dist[next.begin()->first];
        d = d*2 - 1;
        cout << d;
    }




    return 0;
}
