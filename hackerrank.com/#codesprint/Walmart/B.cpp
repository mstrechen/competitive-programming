#include<iostream>

using namespace std;

const long long MOD = 1000000009;
const int offset = 100;

long long dyn[101][202];
          //d[ i ][delta];

long long unused[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int x;
    cin >> n;
    for(int _i = 0; _i<n; _i++)
    {
        cin >> x;
        for(int i = 100-x; i>=-x+1; i--)
        {
            dyn[x][i+offset]+=dyn[x+i][i+offset] + unused[x+i];
            dyn[x][i+offset]%=MOD;
        }
        unused[x]++;
    }
    long long ans = 0;
    for(int i = 0;i<101; i++)
        for(int j = 0;j<202; j++)
            if(dyn[i][j])
            {
                ans+=dyn[i][j];
            }

    cout << ans%MOD + n + 1;


    return 0;
}
