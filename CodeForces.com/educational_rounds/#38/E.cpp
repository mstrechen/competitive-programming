#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

const long long MOD = 1000*1000*1000 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int n;
    cin >> n;
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for(int i = 1; i <=n; i++)
        fact[i] = fact[i - 1] * i;
    
    vector<long long > a(n);
    for(auto & i : a)
        cin >> i;
    
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        if(i != 0 && a[i] == a[i - 1])
            continue;
        
    }
    

    return 0;
}