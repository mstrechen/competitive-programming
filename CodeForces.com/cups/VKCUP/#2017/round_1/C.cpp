#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> operator + (const vector<int> & a, const vector<int> & b)
{
    vector<int> res(a.size());

    for(int i = 0; i<(int)a.size(); i++)
        res[i] = a[i] + b[i];

    return res;
}
void operator += (vector<int> & a, const vector<int> & b)
{
    for(int i = 0; i<(int)a.size(); i++)
        a[i] += b[i];
}

void operator ^= (vector<int> & a, int p)
{
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin()+p+1);
    reverse(a.begin()+p+1, a.end());
}
struct Tree
{
    int size;
    int k;
    vector<vector<int> > e{(size_t)size};
    vector<vector<int> > cnt;
    vector<int> subtree{vector<int>(size, 1)};
    long long ans{0};


    Tree(int n, int k) : size(n), k(k), cnt(size, vector<int>(k, 0) ) {}

    void addEdge(int x, int y)
    {
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }


    int dfs(int v, int from)
    {
        cnt[v][0]++;
        for(auto to : e[v])
            if(to != from)
            {
                int tmp = dfs(to, v);
                ans += cnt[to][1] * 1LL * (size - tmp);

                for(int i = 1; i<k; i++)
                    for(int j = 1; j<k; j++)
                        if(i+j <= k+1 && ((i != k-1 || j != 2) ||  (j != k-1 || i != 2)))
                            ans -= cnt[to][i] * 1LL * cnt[v][j];

                cnt[v] += cnt[to];
                subtree[v] += tmp;
            }
        cnt[v]^=0;
        return subtree[v];
    }

    int dfsFor1(int v, int from)
    {
         for(auto to : e[v])
            if(to != from)
            {
                int tmp = dfsFor1(to, v);
                ans += tmp * 1LL * (size - tmp);
                subtree[v] += tmp;
            }
        return subtree[v];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    Tree T(n,k);

    for(int i = 1; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        T.addEdge(x,y);
    }

    if(k == 1)
        T.dfsFor1(0, -1);
    else
        T.dfs(0, -1);

    cout << T.ans;

    return 0;
}
