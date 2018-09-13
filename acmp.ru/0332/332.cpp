#include<iostream>
#include<vector>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int> > dist(n+1, vector<int>(n+1,0));

    for(int i = 0; i<n; i++)
        for(int j = i; j<n; j++)
        {
            cin >> dist[i][j+1];
            dist[j+1][i] = dist[i][j+1];
        }
    for(int k = 0; k<=n; k++)
        for(int i = 0; i<=n; i++)
            for(int j = 0; j<=n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    cout << dist[0][n];



    return 0;
}
