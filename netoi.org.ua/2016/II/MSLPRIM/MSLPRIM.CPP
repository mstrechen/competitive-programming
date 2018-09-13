#include<iostream>
#include<bitset>

using namespace std;

bitset<77*77+1> dp[77][77+2], res;
int a[77][77+2];


const int countOfGoodNumbers = 22;
const int goodNumbers[countOfGoodNumbers] =  {   4,    7,                                         //2
                                                44,   47,   74,   77,                             //4
                                               444,  447,  474,  477,  744,  747,  774,  777,     //8
                                              4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777};    //8


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        for(int j = 1; j<=m; j++)
            cin >> a[i][j];

    for(int i = 1; i<=m; i++)
        dp[0][i][ a[0][i] ] = 1;

    for(int i = 1; i<n; i++)
        for(int j = 1; j<=m; j++)
        {
            dp[i][j]|=dp[i-1][j-1];
            dp[i][j]|=dp[i-1][j];
            dp[i][j]|=dp[i-1][j+1];

            dp[i][j]<<=a[i][j];
        }

    for(int i = 1; i<=m; i++)
        res|=dp[n-1][i];


    for(int i = countOfGoodNumbers-1; i>=0; i--)
    if(res[goodNumbers[i]])
    {
            cout << goodNumbers[i];
            return 0;
    }

    cout << -1;

    return 0;
}
