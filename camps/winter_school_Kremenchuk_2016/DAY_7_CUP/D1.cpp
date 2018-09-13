#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1000*1000*1000 + 7;

const int SQRT = 316;

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

    if(m<SQRT)
    {
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
    }
    else
    {
        vector<vector<long long> > add(n, vector<long long>(n,0));
        for(int i = 0; i<n; i++)
            add[i][i] = 1;

        while(q--)
        {
            int x,y;
            cin >> x >> y;
            x--;
            y--;

            for(int i = 0; i<n; i++)
            {
                add[x][i] += add[y][i];
                add[x][i]%=MOD;
            }
        }


        vector<vector<int> > tableNew(n, vector<int>(m,0));

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                long long current = 0;
                for(int k = 0; k<n; k++)
                    current += (table[k][j]*add[i][k])%MOD;

                cout << current%MOD << ' ';
            }
            cout << '\n';
        }

    }




    return 0;
}

