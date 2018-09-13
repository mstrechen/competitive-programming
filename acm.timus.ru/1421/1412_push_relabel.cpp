#include<iostream>
#include<numeric>
#include<vector>
#include<queue>
#include<cmath>

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

    void init(queue<int> & Q, vector<char> & used)
    {
        f.assign(size, vector<int>(size, 0));
        e.assign(size, 0);
        h.assign(size, 0);
        h[be] = 2*sqrt(size);
        used[be] = 1;
        used[en] = 1;

        for(int i = 0; i<size; i++)
            if(c[be][i])
            {
                f[be][i] = c[be][i];
                f[i][be] = -c[be][i];
                if(i!=en)
                {
                    Q.push(i);
                    used[i] = 1;
                }
            }
        for(int i = 0; i<size; i++)
            e[i] = f[be][i];
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

    int findMaxFlow()
    {
        queue<int> Q;
        vector<char> used(size, 0);
        init(Q, used);

        while(!Q.empty())
        {
            int i = Q.front();
            for(int j = 0; j<size; j++)
            {
                if(c[i][j] - f[i][j] > 0)
                {
                    if(h[i] > h[j])
                    {
                        push(i,j);
                        if(!used[j])
                        {
                            Q.push(j);
                            used[j] = 1;
                        }
                    }
                }
            }
            if(e[i] != 0)
            {
                h[i]++;
            }
            else
            {
                used[i] = 0;
                Q.pop();
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
