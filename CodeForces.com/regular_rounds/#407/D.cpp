#include<iostream>
#include<vector>

using namespace std;

struct Graph
{
    vector<vector<int>> e;
    vector<char> backToMe;
    vector<int> used;
    long long eCnt{0};
    long long  backCnt{0};

    Graph(int n) : e(n), backToMe(n,0), used(n, 0)
    {
    }

    void add(int x, int y)
    {
        eCnt++;
        if(x == y)
        {
            backToMe[x-1] = 1;
            backCnt++;
        }
        else
        {
            e[x-1].push_back(y-1);
            e[y-1].push_back(x-1);
        }
    }

    long long dfs(int i)
    {
        if(used[i])
            return 0;

        used[i] = 1;
        long long ans = e[i].size() + backToMe[i];
        for(auto j : e[i])
            ans+=dfs(j);

        return ans;
    }
    bool check()
    {
        int cnt = 0;
        for(int i = 0; i<(int)e.size(); i++)
        {
            if(dfs(i))
                cnt++;
        }
        return cnt == 1;
    }

    long long getAns()
    {
        if(!check())
            return 0;

        long long answer = 0;
        for(int i = 0; i<(int)e.size(); i++)
        if(e[i].size() >= 2)
        {
            long long tmp = e[i].size();
            answer += tmp*(tmp-1)/2;
        }

        return answer + backCnt*(backCnt-1)/2 + backCnt*(eCnt - backCnt);
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph G(n);

    for(int i = 0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        G.add(x,y);
    }

    cout << G.getAns();

    return 0;
}
