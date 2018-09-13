#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

struct edge
{
    int to, id;
};


struct Graph
{
    vector<string> ans;
    vector<vector<edge> > e;
    vector<int> cntIn;
    vector<int> used;
    Graph(int n) : ans(n), e(26*26*26), cntIn(26*26*26), used(26*26*26){};

    void addEdge(string & a, string & b, int id)
    {
        int from = getHash(a[0],a[1],a[2]);
        int to = getHash(a[0],a[1],b[0]);
        e[from].push_back({to, id});
        cntIn[to]++;
    }

    int getHash(char a, char b, char c)
    {
        return 26*26*(a-'A') + 26*(b-'A') + (c-'A');
    }

    string getByHash(int h)
    {
        string res(3,'a');
        res[2] = char('A' + h%26);
        h/=26;
        res[1] = char('A' + h%26);
        h/=26;
        res[0] = char('A' + h%26);
        return res;
    }

    bool solve()
    {
        for(int v = 0; v<26*26*26; v++)
            if(e[v].size() > 1)
            {
                for(auto & i : e[v])
                    if(used[i.to])
                        return 0;
                    else
                    {
                        used[i.to] = 1;
                        ans[i.id] = getByHash(i.to);
                        cntIn[i.to]--;
                    }
                e[v].clear();
            }

        bool flag = 1;

        int N = 26*26*26;
        while(flag)
        {
            flag = 0;

            for(int i = 0; i<N; i++)
                if(cntIn[i] == 0 && e[i].size())
                {
                    flag = 1;
                    if(used[i] == 0)
                    {
                        used[i] = 1;
                        ans[e[i][0].id] = getByHash(i);
                    }
                    else
                    {
                        if(used[e[i][0].to])
                        {
                            return 0;
                        }
                        else
                        {
                            ans[e[i][0].id] = getByHash(e[i][0].to);
                            used[e[i][0].to] = 1;
                        }
                    }
                    cntIn[e[i][0].to]--;
                    e[i].clear();
                }

        }

        for(int i = 0; i<N; i++)
            if(used[i] && e[i].size())
                return 0;

        for(int i = 0; i<N; i++)
            if(e[i].size())
            {
                ans[e[i][0].id] = getByHash(i);
            }

        return 1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    Graph G(n);

    string a,b;

    for(int i = 0; i<n; i++)
    {
        cin >> a >> b;
        G.addEdge(a,b,i);
    }

    if(G.solve())
    {
        cout << "YES\n";
        for(auto & i : G.ans)
            cout << i << '\n';
    }
    else
    {
        cout << "NO";
    }


    return 0;
}
