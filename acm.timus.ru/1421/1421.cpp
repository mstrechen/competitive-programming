#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;


using edge = pair<int,int>;

struct Network
{
    const static int maxValue = 100;
    const static int maxPartialFlowValue = 64;


    int size;
    int be, en;
    vector<vector<edge>> e;
    vector<int> used;
    vector<vector<int>> posInE;

    int _currentColor{0};
    int _currentLen{maxPartialFlowValue};

    Network(int sz, const vector<int> & firstHalf,
                    const vector<int> & secondHalf)
                    : size(sz*2 + 2),
                      be(size - 2), en(size - 1),
                      e(size), used(size, 0),
                      posInE(size, vector<int>(size))
    {

        for(int i = 0; i<sz; i++)
            for(int j = 0; j<sz; j++)
                addEdge(i, j+sz, maxValue);

        for(int i = 0; i<sz; i++)
        {
            addEdge(be, i, firstHalf[i]);
            addEdge(i + sz, en, secondHalf[i]);
        }
    }

    void addEdge(int i, int j, int value)
    {
        posInE[i][j] = (int)e[i].size();
        posInE[j][i] = (int)e[j].size();
        e[i].push_back({j,value});
        e[j].push_back({i,0});
    }

    bool dfs(int v)
    {
        if(v == en)
            return 1;
        used[v] = _currentColor;

        for(auto & i : e[v])
        {
            if(i.second >= _currentLen && used[i.first]!=_currentColor)
                if(dfs(i.first))
                {
                    i.second-=_currentLen;
                    e[i.first][posInE[i.first][v]].second+=_currentLen;
                    return 1;
                }
        }
        return 0;
    }

    int calculateMaxFlow()
    {
        int flow = 0;
        do
        {
            _currentColor++;
            if(dfs(be))
                flow+=_currentLen;
            else
                _currentLen/=2;

        }
        while(_currentLen!=0);
        return flow;
    }

    int getValue(int i, int j)
    {
        return e[j][posInE[j][i]].second;
    }


};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> firstHalf(n), secondHalf(n);

    for(auto & i : firstHalf)
        cin >> i;
    for(auto & i : secondHalf)
        cin >> i;

    Network NW(n, firstHalf, secondHalf);


    if(NW.calculateMaxFlow() != accumulate(firstHalf.begin(), firstHalf.end(), 0))
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            cout << NW.getValue(i,j+n) << ' ';
        cout << '\n';
    }


    return 0;
}
