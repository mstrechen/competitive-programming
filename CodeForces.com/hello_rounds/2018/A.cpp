#include<iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if(n > 30)
        cout << m;
    else
        cout << (m & ((1 << n) - 1));
    return 0;
}
