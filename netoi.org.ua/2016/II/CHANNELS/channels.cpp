#include<iostream>
#include<cassert>
#include<algorithm>

using namespace std;

const int MAXN = 50 + 2;

const int oo = 1000*1000;

string field[MAXN];

int dist[3][MAXN][MAXN];

bool used[MAXN][MAXN];

void fillColor(int i, int j, char color)
{
    field[i][j] = color;

    if(field[i][j-1]=='X')
        fillColor(i,j-1, color);
    if(field[i][j+1]=='X')
        fillColor(i,j+1, color);
    if(field[i+1][j]=='X')
        fillColor(i+1,j, color);
    if(field[i-1][j]=='X')
        fillColor(i-1,j, color);
}

pair<int,int> Q[MAXN*MAXN];
int Qsize;

void assignDist(int n, int m, int val)
{
    for(int i = m+1; i>=0; i--)
        for(int j = 0; j<3; j++)
        {
            dist[j][0][i] = val;
            dist[j][n+1][i] = val;
        }
    for(int i = n+1; i>=0; i--)
        for(int j = 0; j<3; j++)
        {
            dist[j][i][0] = val;
            dist[j][i][m+1] = val;
        }
}

void findDist(int NUM, int n, int m)
{
    Qsize = 0;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
        {
            if(field[i][j]==NUM)
            {
                Q[Qsize++] = make_pair(i,j);
                dist[NUM][i][j]  = 1;
            }
            else
            if(field[i][j]<3)
                dist[NUM][i][j] = +oo;
        }

    for(int i = 0; i<Qsize; i++)
    {
        int currDist = dist[NUM][Q[i].first][Q[i].second] + 1;

        if(!dist[NUM][Q[i].first-1][Q[i].second])
        {
            Q[Qsize++] = make_pair(Q[i].first-1,Q[i].second);
            dist[NUM][Q[i].first-1][Q[i].second] = currDist;
        }
        if(!dist[NUM][Q[i].first+1][Q[i].second])
        {
            Q[Qsize++] = make_pair(Q[i].first+1,Q[i].second);
            dist[NUM][Q[i].first+1][Q[i].second] = currDist;
        }
        if(!dist[NUM][Q[i].first][Q[i].second-1])
        {
            Q[Qsize++] = make_pair(Q[i].first,Q[i].second-1);
            dist[NUM][Q[i].first][Q[i].second-1] = currDist;
        }
        if(!dist[NUM][Q[i].first][Q[i].second+1])
        {
            Q[Qsize++] = make_pair(Q[i].first,Q[i].second+1);
            dist[NUM][Q[i].first][Q[i].second+1] = currDist;
        }
    }
}

void fillDist(int n, int m, int val)
{
    for(int k = 0; k<3; k++)
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=m; j++)
                if(dist[k][i][j]==0)
                    dist[k][i][j] = +oo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i<=n; i++)
    {
        cin >> field[i];
        field[i] = '_'+field[i];
    }
    int currentColor = 0;

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            if(field[i][j] == 'X')
                fillColor(i,j, char(currentColor++));

    assert(currentColor==3);

    assignDist(n,m,+oo);


    findDist(0, n, m);
    findDist(1, n, m);
    findDist(2, n, m);

    fillDist(n,m, +oo);

    int ans = +oo;

    int distToLakes[3][3] = {{+oo, +oo, +oo},{+oo, +oo, +oo},{+oo, +oo, +oo}};

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
        {

            ans = min(ans, dist[0][i][j]+dist[1][i][j]+dist[2][i][j] - 5);

            if(field[i][j] < 3)
            {
                for(char k = 0; k<3; k++)
                    if(k!=field[i][j])
                    {
                        distToLakes[k][field[i][j]]  = min(distToLakes[k][field[i][j]], dist[k][i][j-1] - 1);
                        distToLakes[k][field[i][j]]  = min(distToLakes[k][field[i][j]], dist[k][i][j+1] - 1);

                        distToLakes[k][field[i][j]]  = min(distToLakes[k][field[i][j]], dist[k][i+1][j] - 1);
                        distToLakes[k][field[i][j]]  = min(distToLakes[k][field[i][j]], dist[k][i-1][j] - 1);
                    }
            }
        }

    ans = min(ans, distToLakes[0][1] + distToLakes[0][2]);
    ans = min(ans, distToLakes[1][0] + distToLakes[1][2]);
    ans = min(ans, distToLakes[2][0] + distToLakes[2][1]);

    cout << ans;


    return 0;
}
