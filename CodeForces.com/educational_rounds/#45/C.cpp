#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for(auto & i : s)
        cin >> i;
    
    map<int, int> fst, sec;
    for(auto & i : s){
        int bal = 0, minbal = 0;
        for(auto c : i){
            if(c == '(')
                bal++;
            else
                bal--, minbal = min(minbal, bal);
        }
        if(minbal >= 0){
            fst[bal]++;
        }
        if(minbal >= bal){
            sec[bal]++;
        }
    }
    long long ans = 0;
    for(auto & i : fst){
        ans += i.second * 1LL * sec[-i.first];
    }
    cout << ans;

    
    return 0;
}