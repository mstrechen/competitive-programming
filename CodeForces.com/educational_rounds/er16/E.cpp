#include<iostream>
#include<set>

using namespace std;

const int MAXN = 10000500;
const long long MAXDIST = 1000000000000000000;
set<pair<long long, int> > Q;

long long dist[MAXN];
bool used[MAXN];

int main()
{
    ios::sync_with_stdio(false);

    for(int i = 0; i<MAXN; i++)
        dist[i] = MAXDIST;

    long long n, x,y;
    pair<long long, int> tmp;

    cin >> n >> x >> y;

    Q.insert({x,1});
    dist[1] = x;

    while(1)
    {

        tmp = *Q.begin();
        Q.erase(Q.begin());

        if(tmp.second==n)
        {
            cout << tmp.first;
            return 0;
        }
        if(tmp.second>1&&dist[tmp.second-1]>tmp.first+x)
        {
            Q.erase({dist[tmp.second-1], tmp.second-1});
            dist[tmp.second-1] = tmp.first+x;
            Q.insert({tmp.first+x, tmp.second-1});
        }
        if(tmp.second<=n&&dist[tmp.second+1]>tmp.first+x)
        {
            Q.erase({dist[tmp.second+1], tmp.second+1});
            dist[tmp.second+1] = tmp.first+x;
            Q.insert({tmp.first+x, tmp.second+1});
        }
        if(tmp.second<=n/2&&dist[tmp.second*2]>tmp.first+y)
        {
            Q.erase({dist[tmp.second*2], tmp.second*2});
            dist[tmp.second*2] = tmp.first+y;
            Q.insert({tmp.first+y, tmp.second*2});
        }
    }
    return 0;
}
