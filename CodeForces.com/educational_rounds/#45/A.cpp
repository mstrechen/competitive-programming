#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    long long cnt1 = (n / m) * m, cnt2 = (n / m + 1) * (m);

    cout << min((n -  cnt1) * b, (cnt2 - n) * a);



    return 0;
}