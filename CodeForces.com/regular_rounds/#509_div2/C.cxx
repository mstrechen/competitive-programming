#include<iostream>
#include<set>
#include<vector>

const int INF = 2e9;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, d;
    cin >> n >> m >> d;
    
    set<pair<int, int> > S;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        S.insert({x, i});
    }

    int days = 0;
    vector<int> res(n);
    while(!S.empty()){
        days++;
        int x = -2e9;
        do{
            auto it = S.lower_bound({x + d + 1, 0});
            if(it != S.end())
                x = it->first,
                res[it->second] = days,
                S.erase(it);
            else
                break;
        }while(true);
    }

    cout << days << '\n';
    for(auto & i : res)
        cout << i << ' ';

    
    return 0;
}