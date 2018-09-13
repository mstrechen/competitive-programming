#include<iostream>
#include<queue>

using namespace std;


char a[105][105];

int dist[105][105];

int main(){
	ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int beX, beY;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='*')
            {
                beX = i;
                beY = j;
            }
        }
    queue<pair<int,int> > q;
    q.push({beX, beY});
    dist[beX][beY] = 1;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(a[x+1][y] == '0' && dist[x+1][y] == 0)
        {
            dist[x+1][y] = dist[x][y] + 1;
            q.push({x+1,y});
        }
        if(a[x-1][y] == '0' && dist[x-1][y] == 0)
        {
            dist[x-1][y] = dist[x][y] + 1;
            q.push({x-1,y});
        }
        if(a[x][y+1] == '0' && dist[x][y+1] == 0)
        {
            dist[x][y+1] = dist[x][y] + 1;
            q.push({x,y+1});
        }
        if(a[x][y-1] == '0' && dist[x][y-1] == 0)
        {
            dist[x][y-1] = dist[x][y] + 1;
            q.push({x,y-1});
        }
    }

    int minWay = 100500, minId = -1;
    int x,y;
    cin >> n;
    for(int  i = 0; i<n; i++)
    {
        cin >> x >> y;
        if(dist[x][y]&&dist[x][y]<minWay)
        {
            minId = i+1;
            minWay = dist[x][y];
        }
    }
    cout << minId;



	return 0;
}
