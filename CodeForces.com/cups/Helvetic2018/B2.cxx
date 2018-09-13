#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

using treeset = set<pair<int, int>, greater<pair<int, int> > > ;

struct tree{
    int size;
    vector<int> depth,
                depth_v;
    vector<int> p;
    vector<vector<int> > e;
    vector<char> used;

    tree(int n) : size(n), depth(n), depth_v(n), p(n),  e(n), used(n, 0){}

    void add_edge(int x, int y){
        --x, --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    pair<int, int> find_depth(int v, int from = -1){
        p[v] = from;
        depth[v] = 1;
        depth_v[v] = v;
        
        
        for(auto i : e[v])
        if(i != from){
            auto tmp = find_depth(i, v);
            if(depth[v] <  tmp.first + 1)
                depth[v] = tmp.first + 1,
                depth_v[v] = tmp.second;
        }
        return {depth[v], depth_v[v]};
    }

    mutable vector<int> dist;
    void dfs_dist(int v, int from = -1, int d = 0){
        dist[v] = d;
        for(auto i : e[v])
        if(i != from)
            dfs_dist(i, v, d + 1);
    }
    
    int mark(){
        dist.assign(size, 0);
        dfs_dist(0);
        int last = max_element(dist.begin(), dist.end()) - dist.begin();
        
        find_depth(last);
        return last;
    }



    int splittree(treeset & ts){
        if(ts.size() == 0)
            return 0;
        auto v = *ts.begin();
        ts.erase(ts.begin());

        for(int i = depth_v[v.second];;){
            used[i] = 1;

            if(i == v.second)
                break;
            else
                 i = p[i];
        }   
        
        for(int i = depth_v[v.second];;){
            for(auto j : e[i])
            if(!used[j])
                ts.insert({depth[j], j});
            
            if(i == v.second)
                break;
            else
                 i = p[i];
        }   
        

        return v.first;
    }

    vector<int> find_anwer(){
        int fst = mark();
        treeset subtrees;
        depth[fst]--;
        subtrees.insert({depth[fst], fst});

        vector<int> ans = {1};

        for(int i = 1; i < size; i++)
            ans.push_back(ans.back() + splittree(subtrees));
        
        return ans;
    }
    
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    tree T(n);

    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        T.add_edge(x, y);
    }
    auto res = T.find_anwer();
    for(auto & i : res)
        cout << i << ' ';

    return 0;
}