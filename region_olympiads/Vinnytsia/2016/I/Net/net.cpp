#include<iostream>

using namespace std;

int e[205][205];
int dist[205];
int Q[205];

int mymax(int a, int b)
{
    return a>b? a:b;
}

int mymin(int a, int b)
{
    return a>b? a:b;
}

int bfs(int _i, int n)
{
    for(int i = 0; i<n; i++)
        dist[i] = 0;
    dist[_i] = 1;

    int frontI = 1, backI = 0;
    Q[0] = _i;

    while(frontI>backI)
    {
        int v = Q[backI++];
        for(int i = 1; i<=e[v][0]; i++)
            if(!dist[e[v][i]])
            {
                dist[e[v][i]] = dist[v]+1;
                Q[frontI++] = e[v][i];
            }
    }
    int maxDist = 0;
    for(int i = 0; i<n; i++)
    {
        if(dist[i]==0)
            return -1;
        maxDist = mymax(maxDist, dist[i]);
    }
    return maxDist-1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    int from,to;
    for(int i = 0; i<m; i++)
    {
        cin >> from >> to;
        from--;
        to--;
        e[from][++e[from][0]] = to;
    }
    int minWay = bfs(0, n),
        minV = 0;
    for(int i = 1; i<n; i++)
    {
        int tmp = bfs(i, n);
        if((tmp<minWay&&tmp!=-1) || minWay == -1)
        {
            minWay = tmp;
            minV = i;
        }
    }
    if(minWay==-1)
        cout << -1; 
    else
        cout << minV+1;
    return 0;
}
