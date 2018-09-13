#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int gcd(int x, int y){
    while(x && y){
        x %= y;
        swap(x, y);
    }
    return x + y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    int n;
    int k;
    cin >> n >> k;
    int ans = k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ans = gcd(ans, a);
    }
    cout << k / ans << '\n';
    for(int i = 0; i < k/ans; i++){
        cout << i * ans << ' ';
    }

    return 0;
}