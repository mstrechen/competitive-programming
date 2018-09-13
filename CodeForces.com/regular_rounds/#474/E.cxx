#include<iostream>
#include<vector>

using namespace std;

const long long mod = 1000*1000*1000 + 7;

struct tree{
    int size;
    vector<vector<int> > e;
    vector<int> values;

    tree(int n) 
    :   size(n), 
        e(n),
        values(n){}

    void add_edge(int x, int y){
        --x, --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    void read_values(istream & in){
        for(int i = 0; i < size; i++)
            in >> values[i];
    }

    mutable long long ans{0};

    pair<long long, long long> get(int v, int prev){
        ans += values[v];
        //   even,      odd ways
        pair<long long, long long> to_top = {0, values[v]};

        for(auto i : e[v])
        if(v != prev){
            auto tmp = to_top;
            ans += to_top
        }
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}