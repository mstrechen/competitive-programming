#include<iostream>
#include<vector>

using namespace std;

long long gcd(long long a, long long b){
    while(a && b)
        a %= b,
        swap(a, b);
    return a + b;
}
long long lcm(long long a, long long b){
    return a * b / gcd(a, b);
}

int ans(long long a, long long b, vector<int> primes){
    long long n = lcm(a, b) / gcd(a, b);
    int op = 0;
    for(auto & i : primes)
        if(n % i == 0)
            n /= i,
            op++;
    if(n == 1)
        return op;
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, p;
    cin >> a >> b >> p;
    vector<int> primes(p);
    for(auto & i : primes)
        cin >> i;

    int Ans = ans(a, b, primes);
    if(Ans >= 0)
        cout << "YES" << '\n' << Ans;
    else
        cout << "NO";

    return 0;
}
