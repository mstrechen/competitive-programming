#include<iostream>
#include<vector>
#include<set>

const long long NO_ANS = 3e18;

using namespace std;

struct Graph{
    int size;
    vector<vector<pair<int, long long> > > e;

    Graph(int n) : size(n + 1), e(n + 1){

    } 
    void addEdge(int a, int b, long long u){
        e[a - 1].emplace_back(b - 1, u*2);
        e[b - 1].emplace_back(a - 1, u*2);
    }
    void addConcert(int i, long long u){
        e[i].emplace_back(size - 1, u);
        e[size - 1].emplace_back(i, u);
    }

    vector<long long> runDijkstra (){
        set<pair<long long, int> > q;
        q.emplace(0, size - 1);

        vector<long long> dist(size, NO_ANS);
        dist[size - 1] = 0;

        while(!q.empty()){
            long long D = q.begin()->first;
            int v = q.begin()->second;
            q.erase(q.begin());
            for(pair<int, long long> u : e[v]){
                if(dist[u.first] > D + u.second){
                    q.erase({dist[u.first], u.first});
                    dist[u.first] = D + u.second;
                    q.emplace(dist[u.first], u.first);
                }
            }
        }
        return dist;
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Graph G(n);
    for(int i = 0; i < m; i++){
        int x, y;
        long long d;
        cin >> x >> y >> d;
        G.addEdge(x, y, d);
    }
    for(int i = 0; i < n; i++){
        long long u;
        cin >> u;
        G.addConcert(i, u);
    }

    auto d = G.runDijkstra();
    for(int i = 0; i < n; i++)
        cout << d[i] << ' ';

    

    return 0;
}