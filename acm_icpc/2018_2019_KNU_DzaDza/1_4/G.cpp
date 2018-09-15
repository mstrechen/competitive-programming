#include<iostream>



using namespace std;

long long ans(long long n){
    if(n > 10)
        return 1 + __builtin_popcountll(n);
    else
        return __builtin_popcountll(n + (1 << n));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    long long x;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x;
        cout << ans(x) << '\n';
    }


    return 0;
}

