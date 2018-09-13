#include<iostream>


using namespace std;

const int MAXN = 105;
const int MOD = 101;


char dp[MAXN][MAXN][MAXN][MAXN];

int field[MAXN][MAXN];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;


    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cin >> field[i][j];


    if(field[1][1] == field[n][n])
        dp[1][1][n][n] = 1;

    for(int diag = 3; diag<n+2; diag++)
    {
        for(int x = 1; x<diag; x++)
        {
            int y = diag - x;
            for(int x_0 = min(diag-1, n+1-x); x_0>=1 && diag + y <= n+1 + x_0; x_0--)
            {
                int x0 = n+1 - x_0;
                int y0 = n+1 - (diag - x_0);
                if(field[x][y] == field[x0][y0])
                    dp[x][y][x0][y0] = ((int)dp[x-1][y][x0+1][y0] +
                                             dp[x-1][y][x0][y0+1] +
                                             dp[x][y-1][x0][y0+1] +
                                             dp[x][y-1][x0+1][y0])%MOD;
            }
        }
    }

    int ans = 0;

    for(int i = 1; i<=n; i++)
        ans+=dp[i][n+1 - i][i][n+1 - i];

    cout << ans%MOD;

    return 0;
}
