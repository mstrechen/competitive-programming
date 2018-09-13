#include<iostream>
#include<vector>

using namespace std;

const char _AND = 0,
          _OR = 1,
          _XOR = 2,
          _NOT = 3,
          _IN = 4;  

struct Graph{
    int n;
    vector<char> value;
    vector<pair<int, int> > e;
    vector<char> type;

    Graph(int size) : n(size), value(size), e(size), type(size){}

    void addVertex(int i, int t, int l, int r = 0){
        type[i] = t;
        if(t == _IN)
            value[i] = l;
        e[i].first = l;
        e[i].second = r;
    }

    char value_dfs(int v){
        if(type[v] == _IN)
            return value[v];
        if(type[v] == _NOT)
            return (value[v] = !value_dfs(e[v].first));
        if(type[v] == _OR)
            return value[v] = (value_dfs(e[v].first) || value_dfs(e[v].second));
        if(type[v] == _XOR)
            return value[v] = (value_dfs(e[v].first) ^ value_dfs(e[v].second));
        if(type[v] == _AND)
            return value[v] = (value_dfs(e[v].first) && value_dfs(e[v].second));
        
        throw string("WHAAAAAAT");
    }

    void redefine_dfs(int v, char INITIAL_VALUE, char WAS_BLOCKED = 0){
        if(type[v] == _IN){
            if(WAS_BLOCKED)
                value[v] = INITIAL_VALUE;
            else
                value[v] = !INITIAL_VALUE;
            return;
        } 
        if(type[v] == _XOR){
            redefine_dfs(e[v].first, INITIAL_VALUE, WAS_BLOCKED);
            redefine_dfs(e[v].second, INITIAL_VALUE, WAS_BLOCKED);
            return;
        }
        if(type[v] == _NOT){
            redefine_dfs(e[v].first, INITIAL_VALUE, WAS_BLOCKED);
            return;
        }
        if(type[v] == _AND){
            if(WAS_BLOCKED || (value[e[v].first] == 0 && value[e[v].second] == 0)){
                redefine_dfs(e[v].first, INITIAL_VALUE, 1);
                redefine_dfs(e[v].second, INITIAL_VALUE, 1);
                return;
            }
            if(value[e[v].first] == 1 && value[e[v].second] == 1){
                redefine_dfs(e[v].first, INITIAL_VALUE);
                redefine_dfs(e[v].second, INITIAL_VALUE);
                return;
            }
            if(value[e[v].first] == 0 && value[e[v].second] == 1){
                redefine_dfs(e[v].first, INITIAL_VALUE);
                redefine_dfs(e[v].second, INITIAL_VALUE, 1);
                return;
            }
            if(value[e[v].first] == 1 && value[e[v].second] == 0){
                redefine_dfs(e[v].first, INITIAL_VALUE, 1);
                redefine_dfs(e[v].second, INITIAL_VALUE);
                return;
            }
        }

        if(type[v] == _OR){
            if(WAS_BLOCKED || (value[e[v].first] == 1 && value[e[v].second] == 1)){
                redefine_dfs(e[v].first, INITIAL_VALUE, 1);
                redefine_dfs(e[v].second, INITIAL_VALUE, 1);
                return;
            }
            if(value[e[v].first] == 0 && value[e[v].second] == 0){
                redefine_dfs(e[v].first, INITIAL_VALUE);
                redefine_dfs(e[v].second, INITIAL_VALUE);
                return;
            }
            if(value[e[v].first] == 0 && value[e[v].second] == 1){
                redefine_dfs(e[v].first, INITIAL_VALUE, 1);
                redefine_dfs(e[v].second, INITIAL_VALUE);
                return;
            }
            if(value[e[v].first] == 1 && value[e[v].second] == 0){
                redefine_dfs(e[v].first, INITIAL_VALUE);
                redefine_dfs(e[v].second, INITIAL_VALUE, 1);
                return;
            }
        }
        throw string("STRANGE THINGS");
    }


    string getAns(){
        value_dfs(0);

        redefine_dfs(0, value[0]);

        string ans;
        for(int i = 0; i < n; i++)
            if(type[i] == _IN)
                ans += (value[i] + '0');
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Graph G(n);

    for(int i = 0; i < n; i++){
        string s;
        int l, r;
        cin >> s >> l;
        if(s == "AND" || s == "XOR" || s == "OR")
            cin >> r;
        if(s == "AND") G.addVertex(i, _AND, l - 1, r - 1); else 
        if(s == "OR") G.addVertex(i, _OR, l - 1, r - 1); else 
        if(s == "XOR") G.addVertex(i, _XOR, l - 1, r - 1); else 
        if(s == "IN") G.addVertex(i, _IN, l); else 
        if(s == "NOT") G.addVertex(i, _NOT, l - 1); 
    }
    cout << G.getAns();



    return 0;
}