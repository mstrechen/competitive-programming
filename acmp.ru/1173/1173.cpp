#include<iostream>

using namespace std;


int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int euler(int n){
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
    return ans;
}

long long sqr(int x, int mod){
    return (x*1LL*x)%mod;
}

long long binpow(int a, int x, int mod){
    if(x == 0)
        return 1;
    if(x&1)
        return (binpow(a, x-1, mod)*a)%mod;
    return sqr(binpow(a, x/2, mod), mod);
}

int main(){

    int n, m;
    cin >> n >> m;


    long long tmp = binpow(n, euler(m) - 1, m);

    if(gcd(n, m) == 1)
        cout << tmp;
    else
        cout << "No solution";

    return 0;
}
