#include<iostream>
#include<vector>
#include<cmath>
#include<set>

using namespace std;

const long long oo = 1e18;

long long dp[305][305], h[305][305];
int costOfRoad, costOfBridge, costOfTun;


int getcode(int i, int j)
{
    return i*301+j;
}

void addRoads(int i, int j, vector<vector<pair<int, int> > > & edges)
{
    int code = getcode(i,j);
    if(i>0&&abs(h[i][j] - h[i-1][j])<2)
    {
        edges[code].push_back({getcode(i-1,j), costOfRoad});
        edges[getcode(i-1,j)].push_back({code, costOfRoad});
    }
    if(j>0&&abs(h[i][j] - h[i][j-1])<2)
    {
        edges[code].push_back({getcode(i,j-1), costOfRoad});
        edges[getcode(i,j-1)].push_back({code, costOfRoad});
    }
}

void addBridges(int i, int j, vector<vector<pair<int, int> > > & edges)
{
    int i_1,j_1;


    for(i_1 = i-1; i_1>=0 && h[i_1][j] < h[i][j]; i_1--);

    if(i_1>=0&&h[i][j]==h[i_1][j])
    {
        edges[getcode(i,j)].push_back({getcode(i_1, j), costOfBridge*(i-i_1-1) + costOfRoad});
        edges[getcode(i_1,j)].push_back({getcode(i, j), costOfBridge*(i-i_1-1) + costOfRoad});
    }

    for(j_1 = j-1; j_1>=0 && h[i][j_1] < h[i][j]; j_1--);

    if(j_1>=0&&h[i][j]==h[i][j_1])
    {
        edges[getcode(i,j)].push_back({getcode(i, j_1), costOfBridge*(j-j_1-1) + costOfRoad});
        edges[getcode(i,j_1)].push_back({getcode(i, j), costOfBridge*(j-j_1-1) + costOfRoad});
    }
}
void addTunnels(int i, int j, vector<vector<pair<int, int> > > & edges)
{
    int i_1,j_1;


    for(i_1 = i-1; i_1>=0 && h[i_1][j] > h[i][j]; i_1--);

    if(i_1>=0&&h[i][j]==h[i_1][j])
    {
        edges[getcode(i,j)].push_back({getcode(i_1, j), costOfTun*(i-i_1-1) + costOfRoad});
        edges[getcode(i_1,j)].push_back({getcode(i, j), costOfTun*(i-i_1-1) + costOfRoad});
    }

    for(j_1 = j-1; j_1>=0 && h[i][j_1] > h[i][j]; j_1--);

    if(j_1>=0&&h[i][j]==h[i][j_1])
    {
        edges[getcode(i,j)].push_back({getcode(i, j_1), costOfTun*(j-j_1-1) + costOfRoad});
        edges[getcode(i,j_1)].push_back({getcode(i, j), costOfTun*(j-j_1-1) + costOfRoad});
    }
}



void addEdges(int i, int j, vector<vector<pair<int, int> > > & edges)
{
    addRoads(i, j, edges);
    addBridges(i, j, edges);
    addTunnels(i, j, edges);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i<305; i++)
        h[i][0] = +oo;
    for(int i = 0; i<305; i++)
        h[0][i] = +oo;

    int n,m;
    cin >> n >> m >> costOfRoad >> costOfBridge >> costOfTun;

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin >> h[i][j];

    vector<vector<pair<int,int> > > edges(305*305);

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
        {
            addEdges(i,j, edges);
        }

    vector<long long> dist(305*305, +oo);
    dist[0] = 0;
    set<pair<long long, int> > Q = {{0,0}};

    while(!Q.empty())
    {
        auto cur = *Q.begin();
        long long x = cur.first;
        int v = cur.second;


        Q.erase(Q.begin());

        for(auto i : edges[v])
        {
            if(dist[i.first]>x+i.second)
            {
                Q.erase({dist[i.first],i.first});
                dist[i.first] = x+i.second;
                Q.insert({dist[i.first], i.first});
            }
        }
    }


    if(dist[getcode(n-1,m-1)]==+oo)
        cout << "not exist";
    else
        cout << dist[getcode(n-1,m-1)] + costOfRoad;


    return 0;
}
