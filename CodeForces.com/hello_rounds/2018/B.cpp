#include<iostream>
#include<vector>

using namespace std;

struct Tree{
    int n;
    vector<vector<int> > e;
    Tree(int n) : n(n), e(n){}

    void addEdge(int a, int b){
        e[a - 1].push_back(b - 1);
        e[b - 1].push_back(a - 1);
    }
    bool isChristmasTree = 1;
    int dfs(int v, int from){
        if(e[v].size() > 1){
            int cnt = 0;
            for(auto i : e[v])
            if(i != from)
                cnt += dfs(i, v);

            if(cnt < 3)
                isChristmasTree = 0;
            return 0;
        } else
            return 1;
    }
    string check(){
        dfs(0, -1);
        if(isChristmasTree)
            return "Yes";
        else
            return "No";
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Tree T(n);
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        T.addEdge(i, x);
    }

    cout << T.check();

    return 0;
}
