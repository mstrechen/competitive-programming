#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>

using namespace std;


const int INF = 1000*1000*1000;


struct doubleSet{
    int n, m;
    vector<char> usedN, usedM;
    set<pair<int, int> > dir, undir;

    doubleSet(int n, int m) : n(n), m(m), usedN(n, 0), usedM(m, 0){} 

    void insert(const pair<int, int> & a){
        dir.insert(a);
        undir.insert({a.second, a.first});
    }

    void erase(const pair<int, int> & a){
        dir.insert(a);
        undir.insert({a.second, a.first});
    }

    void eraseX(int x){
        auto itBe = dir.lower_bound({x, 0}),
             itEn = dir.lower_bound({x, INF});
    
        for(auto it = itBe; it != itEn; it++)
            undir.erase({it->second, it->first});
        dir.erase(itBe, itEn);
    }
    void eraseY(int y){
        auto itBe = undir.lower_bound({y, 0}),
             itEn = undir.lower_bound({y, INF});
    
        for(auto it = itBe; it != itEn; it++)
            dir.erase({it->second, it->first});
        undir.erase(itBe, itEn);
    }


    int getAns(vector<pair<int, int> > points){
        sort(points.begin(), points.end());
        for(vector<pair<int, int> >::iterator it = points.begin(), next; it != points.end(); it = next){
            next = lower_bound(points.begin(), points.end(), {it->first, INF});
            
        }
    }  
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int> > points(q);
    for(auto & i : points){
        cin >> i.first >> i.second;
        i.first--;
        i.second--;
    } 
    doubleSet DS(n, m);

    cout << DS.getAns(points);



    return 0;
}