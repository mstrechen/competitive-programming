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
    vector<int> cnt(n, 0);

    int finDist = dist[next.begin()->first];

    for(auto & i : next)
    {
        finlist.push_back(i.first);
        for(auto j : e[i.first])
            if(dist[j] == finDist)
                cnt[i.first]++;
    }

    int cntZeroNb = 0;
    int cntOneNb = 0;
    int cntMoreNb = 0;
    int sumMoreNb = 0;

    for(auto i : finlist)
    {
        if(cnt[i] == 0)
            cntZeroNb++;
        else
        {
            if(cnt[i] > 1)
            {
                for(int j : e[i])
                    if(cnt[j]>1)
                    {
                        cout << -1;
                        return 0;
                    }
                cntMoreNb++;
                sumMoreNb+=cnt[i];
            }
            else
            {
                cntOneNb++;
            }
        }
    }

    cntOneNb-=sumMoreNb;
    cntOneNb/=2;
    cntMoreNb+=cntOneNb;

    if(cntZeroNb == 0)
    {
        int diam = finDist*2 - 1;
        cout << diam;
    }
    else
    {
        if(cntMoreNb>0)
        {
            cout << -1;
        }
        else
        {
            int diam = finDist-1;
            while(diam%2 == 0)
                diam/=2;
            cout << diam;
        }
    }







    return 0;
}
