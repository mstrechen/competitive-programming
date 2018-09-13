#include<iostream>
#include<numeric>
#include<vector>
#include<queue>
#include<set>
#include<functional>

using namespace std;


struct Network
{
    int size;
    int be, en;
    vector<vector<int> > c, f{};
    vector<int> h{}, e{};

    Network(int n) : size(n*2 + 2), be(size - 2), en(size - 1),
                     c(size, vector<int>(size, 0))
    {
    }

    using myQueue = set<pair<int,int>, greater<pair<int,int> > >;
    void init(myQueue & Q, vector<char> & used)
    {
        f.assign(size, vector<int>(size, 0));
        e.assign(size, 0);
        h.assign(size, 0);
        h[be] = size;
        e[be] = 1000*1000*1000;
        used[be] = 1;
        used[en] = 1;

        Q.emplace(h[be], be);
    }

    void addEdge(int x, int y, int val)
    {
        c[x][y]+=val;
    }

    void push(int x, int y)
    {
        int delta = min(e[x], c[x][y] - f[x][y]);
        f[x][y] += delta;
        f[y][x] -= delta;
        e[x] -= delta;
        e[y] += delta;
    }

    void relable(int x)
    {
        int H = size;
        for(int y = 0; y<size; y++)
            if(c[x][y] - f[x][y] > 0)
            {
                H = min(H, h[y]);
            }
        h[x] = H + 1;
    }

    int findMaxFlow()
    {
        myQueue Q;
        vector<char> used(size, 0);
        init(Q, used);

        while(!Q.empty())
        {
            int I = Q.begin()->second;
            Q.erase(Q.begin());

            for(int J = 0; J<size; J++)
                if(c[I][J] - f[I][J] > 0 && e[I] && h[I] > h[J])
                {
                    push(I, J);
                    if(J!=be && J!=en)
                        Q.emplace(h[J], J);
                }

            if(I!=be && I!=en && e[I] != 0)
            {
                h[I]++;
                Q.emplace(h[I], I);
            }
        }


        return -accumulate(f[en].begin(), f[en].end(), 0);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Network NW(n);
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            NW.addEdge(i, j+n, 100);

    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        NW.addEdge(NW.be, i, x);
        sum+=x;
    }
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        NW.addEdge(i+n, NW.en, x);
    }



    if(NW.findMaxFlow() != sum)
        cout << "NO";
    else
    {
        cout << "YES\n";
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
                cout << NW.f[i][j+n] << ' ';
            cout << '\n';
        }
    }

    return 0;
}
