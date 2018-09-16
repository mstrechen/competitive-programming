#include<iostream>


using namespace std;

long long gcd(long long x, long long y){
    while(x && y)
        x %= y,
        swap(x, y);
    return x + y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, x, y;
    cin >> a >> b >> x >> y ;
    auto gcd_xy = gcd(x, y);
    x /= gcd_xy, y /= gcd_xy;

    cout << min<long long>(a / x, b / y);

    return 0;
}