#include<iostream>


using namespace std;

const int MAXN = 128;
const int MOD = 101;


char state1[MAXN*MAXN], state2[MAXN*MAXN];

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

    char *curState = state1, *nextState = state2;

    if(field[1][1] == field[n][n])
        nextState[1*MAXN + 1] = 1;

    for(int diag = 3; diag<n+2; diag++)
    {
        swap(curState, nextState);
        for(int x = 1; x<diag; x++)
        {
            int y = diag - x;
            for(int x_0 = min(diag-1, n+1-x); x_0>=1 && diag + y <= n+1 + x_0; x_0--)
            {
                int x0 = n+1 - x_0;
                int y0 = n+1 - (diag - x_0);
                if(field[x][y] == field[x0][y0])
                    nextState[x*MAXN + x_0] = (curState[(x  )*MAXN + (x_0  )]+
                                               curState[(x  )*MAXN + (x_0-1)]+
                                               curState[(x-1)*MAXN + (x_0  )]+
                                               curState[(x-1)*MAXN + (x_0-1)])%MOD;
                else
                    nextState[x*MAXN + x_0] = 0;

            }
        }
    }

    int ans = 0;

    for(int i = 1; i<=n; i++)
        ans+=nextState[i*MAXN + n + 1 - i];

    cout << ans%MOD;

    return 0;
}
