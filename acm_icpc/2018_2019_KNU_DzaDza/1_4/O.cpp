#include<iostream>
#include<cmath>
using namespace std;

bool check(long long x, long long u){
    if(x * (x + 1) / 2 == u)
        return true;
    return false;
}

int main(){

    long long u;
    cin >> u;
    long long x = (-1 + sqrt(1 + 8*u)) / 2;

    if(check(x - 1, u))
        cout << x - 1;
    else
    if(check(x, u))
        cout << x;
    else if(check(x, u))
        cout << x + 1;
    else
        cout << -1;
    return 0;
}
