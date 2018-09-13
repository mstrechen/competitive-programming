#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> a >> b;
    if(a - 1 + b - 1 > n * (n - 1) / 2 || (a == 1 && b == 1 && n == 2)){
        cout << "NO";
    } else {
        cout << "YES";
    }

    
    return 0;
}