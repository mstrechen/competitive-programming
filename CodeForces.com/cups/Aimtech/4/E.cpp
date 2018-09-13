#include<iostream>
#include<vector>

using namespace std;

struct tree{
    int size;
    vector<vector<int> > e;

    mutable vector<int> dist;

    tree(int n)
    : size(n),
      e(n),
      dist(n){}

    void dfs_dist(int v, int prev = -1, int depth = 0) const{
        dist[v] = depth;
        for(auto i : e[v])
            if(i != prev)
                dfs_dist(i, v, depth + 1);
    }

    pair<int, int> get_centroid() const{
        dfs_dist(0);
        dfs_dist(max_element(dist.begin(), dist.end()) - dist.begin());

        int cur_point = max_element(dist.begin(), dist.end()) - dist.begin();
        int diam = dist[cur_point];
        int rad = (diam + 1)/2;

        while(dist[cur_point] != rad){
            for(auto i : e[cur_point])
                if(dist[i] < dist[cur_point]){
                    cur_point = i;
                    break;
                }
        }
        if(diam % 2 == 0)
            return {cur_point, -1};

        for(auto i : e[cur_point])
            if(dist[i] == dist[cur_point] - 1)
                return {cur_point, i};
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
