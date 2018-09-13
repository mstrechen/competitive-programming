#include<iostream>

using namespace std;

const long long MOD = 1000*1000*1000 + 9;

long long sqr(long long x){
    return (x * x) % MOD; 
}
long long binpow(long long x, long long a) {
    if(a == 0)
        return 1;
    if(a & 1)
        return (sqr(binpow(x, a/2)) * x) % MOD;
    return sqr(binpow(x, a/2));
}

long long modpow(long long x, long long a){
    if(a >= 0)
        return binpow(x, a);
    else
        return binpow(binpow(x, -a), MOD - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;

    long long sum = 0;
    for(int i = 0; i < k; i++){
        if(s[i] == '+')
            sum += (modpow(a, n - i) * modpow(b, i)) % MOD;
        else 
            sum -= (modpow(a, n - i) * modpow(b, i) % MOD);
    }

    sum %= MOD;
    sum += MOD;
    sum %= MOD;
    n++;

    long long q = (modpow(b, k) * modpow(a, -k)) % MOD;
    long long N = n/k;

    
    long long mul;
    if(q == 1)
        mul = N;
    else 
        mul = ((modpow(q, N) - 1) * modpow(q - 1, -1)) % MOD;

    sum *= mul;
    
    sum %= MOD;
    sum += MOD;
    sum %= MOD; 
    

    cout << sum;

    return 0;
}