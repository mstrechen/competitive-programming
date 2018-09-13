#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU{
    int size;
    vector<int> p, w;

    DSU(int n) 
      : size(n), p(n), w(n, 1)
    {
        for(int i = 0; i < n; i++)
            p[i] = i;        
    }

    int get(int i){
        if(p[i] == i)
            return i;
        return p[i] = get(p[i]);
    }
        
    bool unite(int i, int j){
        i = get(i), j = get(j);
        if(i != j)
            return 0;
        if(w[i] < w[j])
            p[i] = j;
        else
            w[i] += (w[i] == w[j]),
            p[j] = i;
        p[i] = j;
        return 1;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        

    return 0;
}
