#include<iostream>
#include<vector>
#include<function>

using namespace std;

struct Edge{
    int to, cost, id;
    Edge(int to, int cost, int id) : to(to), cost(cost), id(id){}
};

bool operator < (const Edge & a, const Edge & b){
    return a.cost < b.cost || (a.cost == b.cost && a.id < b.id);
}
struct SmallEdge{
    int cost, id;
    Edge(int cost, int id) : cost(cost), id(id){}
};

bool operator < (const SmallEdge & a, const SmallEdge & b){
    return a.cost < b.cost || (a.cost == b.cost && a.id < b.id);
}


struct Graph{
    int size;
    vector<vector<Edge> > e{vector<vector<Edge> >(size)};

    Graph(int size = 0) : size(size){};

    vector<int> findCycle(){
        vector<int> st;

        function<bool(int, int)> dfs = [&](int v, int from){
            st.push_back(v);


            st.pop_back();
        };

        return st;
    }

};

istream & operator >> (istream & in, Graph & G)
{
    int countOfEdges;
    cin >> G.size >> countOfEdges;
    for(auto & i : G.e)
        i.clear();
    G.e.resize(G.size);

    for(int i = 0; i < countOfEdges; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        G.e[from].emplace_back(to, cost, i+1);
        G.e[to].emplace_back(from, cost, i+1);
    }

    return in;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Graph G;
    cin >> G;

    return 0;
}
