#include<iostream>
#include<vector>

using namespace std;


struct Network
{
    int size;
    int be, en;

    vector<int> used;
    vector<vector<pair<int,int> > > e;
    vector<vector<int>> posInE;

    int _currentColor{0};
    int _currentStream{0};

    Network(int n) :
             size(n), be(0), en(n-1),
             used(n, 0), e(n),
             posInE(n, vector<int>(n, -1) )
    {
    }

    void addEdge(int i, int j, int value)
    {
        if(posInE[i][j] < 0)
        {
            posInE[i][j] = e[i].size();
            posInE[j][i] = e[j].size();
            e[i].push_back({j, value});
            e[j].push_back({i, 0});
        }
        else
        {
            e[i][ posInE[i][j] ].second += value;
        }
    }

    bool dfs(int v)
    {
        if(v == en)
            return 1;
        used[v] = _currentColor;

        for(auto & i : e[v])
            if(i.second >= _currentStream && used[i.first] != _currentColor)
                if(dfs(i.first))
                {
                    i.second -= _currentStream;
                    e[i.first][ posInE[i.first][v] ].second += _currentStream;

                    return 1;
                }
        return 0;
    }

    long long getMaxFlow()
    {
        _currentColor = 0;
        _currentStream = 1<<30;
        used.assign(size, _currentColor);

        long long flow = 0;

        while(_currentStream != 0)
        {
            _currentColor++;

            if(dfs(be))
                flow+=_currentStream;
            else
                _currentStream/=2;
        }

        return flow;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    Network NW(n);

    for(int i = 0; i<m; i++)
    {
        int x,y,val;
        cin >> x >> y >> val;
        NW.addEdge(x-1,y-1,val);
        NW.addEdge(y-1,x-1,val);
    }

    cout << NW.getMaxFlow();



    return 0;
}
