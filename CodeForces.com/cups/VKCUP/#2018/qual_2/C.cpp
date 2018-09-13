#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<tuple>

using namespace std;

vector<tuple<int, int, int> > moves = 
{   
    {0, 0, 1},
    {0, 0, 2},
    {0, 0, 3},
    {0, 1, 0},
    {0, 1, 1},
    {0, 1, 2},
    {0, 1, 3},
    {0, 2, 0},
    {0, 2, 1},
    {0, 2, 2},
    {0, 2, 3},
    {1, 0, 0},
    {1, 0, 1},
    {1, 0, 2},
    {1, 0, 3},
    {1, 1, 0},
    {1, 1, 1},
    {1, 1, 2},
    {1, 1, 3},
    {1, 2, 0},
    {1, 2, 1},
    {1, 2, 2},
    {1, 2, 3},
    
};

long long calcCnk(int n, int k){
    switch(k){
        case 0 : return 1; break;
        case 1 : return n; break;
        case 2 : return n*(n - 1)/2; break;
        case 3 : return n * (n - 1) * (n - 2) / 6; break;
        default : exit(1);
    }
    return -1;
}

struct players{
    int size;
    vector<int> a;
    
    players(int n) : size(n), a(n){}

    void readPlayers(istream & in) {
        for(auto & i : a)
            cin >> i;
        sort(a.begin(), a.end());
    }

    long long getCnt(int l, int r){
        if(l > r)
            return 0;
        int real_cnt = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);

        return real_cnt;
    }

};


int main(){
    ios::sync_with_stdio(false);
    
    int G, D, F;
    cin >> G >> D >> F;

    players goalkeepers(G),
            defenders(D),
            forwarders(F);
    
    goalkeepers.readPlayers(cin);
    defenders.readPlayers(cin);
    forwarders.readPlayers(cin);

    long long ans = 0;

    set<int> all;
    for(auto & i : goalkeepers.a)
        all.insert(i);
    for(auto & i : defenders.a)
        all.insert(i);
    for(auto & i : forwarders.a)
        all.insert(i);
    
    for(auto  x2 : all){
        int x = (x2 + 1)/2;
       
        int A1 = goalkeepers.getCnt(x2, x2);
        int A2 = defenders.getCnt(x2, x2);
        int A3 = forwarders.getCnt(x2, x2);

        int B1 = goalkeepers.getCnt(x, x2-1);
        int B2 = defenders.getCnt(x, x2-1);
        int B3 = forwarders.getCnt(x, x2-1);
        

        for(auto & i : moves){
            ans += calcCnk(A1, get<0>(i)) * calcCnk(B1, 1 - get<0>(i)) * 
                   calcCnk(A2, get<1>(i)) * calcCnk(B2, 2 - get<1>(i)) * 
                   calcCnk(A3, get<2>(i)) * calcCnk(B3, 3 - get<2>(i)); 
        }
    }

    cout << ans;

    return 0;
}