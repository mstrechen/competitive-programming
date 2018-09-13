#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 1;

    for(int i = 2; i * i <= n; i++)
        if(n % i == 0){
            int tmp = 1;
            while(n % i == 0){
                tmp *= i;
                n /= i;
            }
            ans *= tmp - tmp/i;
        }

    if(n > 1)
        ans *= n - 1;

    cout << ans;
    return 0;
}
