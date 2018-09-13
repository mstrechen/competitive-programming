#include<iostream>
#include<set>



using namespace std;

const int INF  = 1000000000;

int dist[1000500];
int a[1000500];

set<pair<int, int> > q;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        dist[i] = INF;
        cin >> a[i];
        a[i]--;
    }
    dist[0] = 0;
    q.insert({0,0});
    while(!q.empty())
    {
        pair<int,int> tmp = *q.begin();
        q.erase(q.begin());
        if(tmp.second!=n-1&&tmp.first+1<dist[tmp.second+1])
        {
            q.erase({dist[tmp.second+1], tmp.second+1});
            q.insert({tmp.first+1, tmp.second+1});
            dist[tmp.second+1] = tmp.first+1;
        }
        if(tmp.first+1<dist[a[tmp.second]])
        {
            q.erase({dist[a[tmp.second]], a[tmp.second]});
            q.insert({tmp.first+1, a[tmp.second]});
            dist[a[tmp.second]] = tmp.first+1;
        }
        if(tmp.second!=0&&tmp.first+1<dist[tmp.second-1])
        {
            q.erase({dist[tmp.second+1], tmp.second-1});
            q.insert({tmp.first+1, tmp.second-1});
            dist[tmp.second-1] = tmp.first+1;
        }
    }
    for(int i = 0; i<n; i++)
    {
        cout << dist[i] << ' ';
    }
    return 0;
}
