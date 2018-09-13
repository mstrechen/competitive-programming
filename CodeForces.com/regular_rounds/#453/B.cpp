#include<iostream>
#include<vector>


using namespace std;

struct graph{
    int n;
    vector<vector<int> > e;
    vector<int> color;
    graph(int n) : n(n), e(n), color(n){}

    void add(int x, int y){
        --x, --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    int dfs(int current, int from, int prevcolor){
        int ans = 0;
        if(color[current] != prevcolor)
            ans++;
        prevcolor = color[current];
        for(auto & i : e[current])
        if(i != from)
        {
            ans += dfs(i, current, prevcolor);
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    graph g(n);


    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        g.add(x, i+1);
    }

    for(auto & i : g.color)
        cin >> i;

    cout << g.dfs(0, -1, -1);

    return 0;
}
