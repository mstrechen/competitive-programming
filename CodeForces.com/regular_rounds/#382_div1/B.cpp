#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(long long a)
{
    if(a==2)
        return 1;
    if(a%2==0)
        return 0;
    for(long long i = 3; i*i<=a; i+=2)
        if(a%i==0)
            return 0;

    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    if(isPrime(n))
    {
        cout << 1;
        return 0;
    }
    if(n%2==0 || isPrime(n-2) )
    {
        cout << 2;
        return 0;
    }
    cout << 3;
    return 0;
}
