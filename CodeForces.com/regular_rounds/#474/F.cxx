#include<iostream>
#include<vector>
#include<unordered_map>
#include<tuple>
#include<cassert>

using namespace std;
using VALUE_T = tuple<int, int, int>;

struct OpenAddressHashTable
{
    static const int size{1000003}; //prime number greater than 1'000'000
    static const int step{50000};
    VALUE_T cleared{make_tuple(-100, -100, -100)};

    vector<VALUE_T> a{size, cleared};
    vector<int> val{vector<int>(size, -1)};

    int hash(const VALUE_T&toHash) const {
    	return int((3*get<0>(toHash) + 2*get<1>(toHash) + get<2>(toHash))%size + size) % size;
    }

    int hash2(const VALUE_T &toHash) const {
    	return int((3*get<0>(toHash) + 2*get<1>(toHash) + get<2>(toHash))%step + step)%step + 1;
    }

    void clear()
    {
        a.assign(size, cleared);
    }

    int & operator [] (const VALUE_T & toInsert)
    {
    	int first = hash(toInsert);
        int i = first;
        int realStep = -1;
        while (true)
        {
            if(a[i] == cleared)
            {
                a[i] = toInsert;
                return val[i]; 
            }
            if(a[i] == toInsert)
                return val[i];

            if (realStep == -1) {
            	realStep = hash2(toInsert);
            }
            i += realStep;
            if (i >= size) {
            	i -= size;
            }
            assert(i!=first && "NO PLACE");
        }
    }

    int count(const VALUE_T & toFind)
    {
    	int first = hash(toFind);
        int i = first;
        int realStep = -1;
        while (true)
        {
            if(a[i] == cleared)
            {
                return 0;
            }
            if(a[i] == toFind)
                return 1;
            if (realStep == -1) {
            	realStep = hash2(toFind);
            }
            i+=realStep;
            if (i >= size) {
            	i -= size;
            }
            assert(i!=first && "NO PLACE");
        }
    }

};


struct graph{
    int size;
            //where, i, weight
    vector<vector<tuple<int, int, int> > > e;
    graph(int n) : size(n + 1), e(n + 1){
        for(int i = 1; i <= n; i++)
            e[0].push_back({i, -1, -1});
    }

    void add_edge(int x, int y, int i, int w){
        e[x].emplace_back(y, i, w);
    }
    mutable OpenAddressHashTable dp;
    
    int get_next(int v, int prev_i, int prev_w){
        if(dp.count({v, prev_i, prev_w})){
            
            return dp[{v, prev_i, prev_w}];
        }
        int ans = 0;
        for(auto & i : e[v]){
            
            if(get<1>(i) > prev_i && get<2>(i) > prev_w)
                ans = max(ans, get_next(get<0>(i), get<1>(i), get<2>(i)));
            
        }
        ans += 1;
        return dp[{v, prev_i, prev_w}] = ans; 
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        g.add_edge(x, y, i, w);
    }

    cout << g.get_next(0, -2, -2) - 2; 

    

    return 0;
}