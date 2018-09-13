#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1000*1000*1000 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<int> > table(n, vector<int>(m,0));

    for(auto & i : table)
        for(auto & j : i)
            cin >> j;

    int q;
    cin >> q;

    while(q--)
    {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        for(int i = 0; i<m; i++)
        {
            table[x][i]+=table[y][i];
            table[x][i]%=MOD;
        }
    }

    for(auto & i : table)
    {
        for(auto & j : i)
            cout << j << ' ';
        cout << '\n';
    }


    return 0;
}

