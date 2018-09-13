#include<iostream>
#include<fstream>

using namespace std;


const int MAX_N = 5001;
int prefix_a[MAX_N][MAX_N];

bool used[MAX_N][MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    int answer = 0;
    char tmp;
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
        {
            cin >> tmp;
            prefix_a[i][j] =  prefix_a[i][j-1]+prefix_a[i-1][j]-prefix_a[i-1][j-1]+ (tmp=='.');
            used[i][j] = (tmp=='.');
        }
    for(int i = 1; i<=n; i++)
    {
        prefix_a[i][m+1] =  prefix_a[i][m]+prefix_a[i-1][m+1]-prefix_a[i-1][m]+1;
    }
    for(int j = 1; j<=m; j++)
    {
        prefix_a[n+1][j] =  prefix_a[n+1][j-1]+prefix_a[n][j]-prefix_a[n][j-1]+1;
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(used[i][j]==0)
            {
                int _i = i;
                int _j = j;
                while(prefix_a[_i][_j]+prefix_a[i-1][j-1]-prefix_a[_i][j-1]-prefix_a[i-1][_j]==0)
                    _j++;
                _j--;
                while(prefix_a[_i][_j]+prefix_a[i-1][j-1]-prefix_a[_i][j-1]-prefix_a[i-1][_j]==0)
                    _i++;
                _i--;
                answer++;

                for(int k = i; k<=_i; k++)
                    for(int l = j; l<=_j; l++)
                        used[k][l] = true;


            }
        }
    }
    cout << answer;

    return 0;
}
