#include <iostream>
#include <cmath>
using namespace std;

long long max(long long a, long long b)
{
    return (a>b?a:b);
}
long long min(long long a, long long b)
{
    return (a<b?a:b);
}
int main(){
	ios::sync_with_stdio(false);
	long long n, a, b, c,d;
    long long countOfVars = 0;
    cin >> n >> a >> b >> c >> d;
    long long _m = max(max(a+b,a+c),max(c+d,d+b));
    long long _n = min(min(a+b,a+c),min(c+d,d+b));
    for(long long i = 1; i<=n; i++)
    {
        countOfVars+=max(0, _n+i+n-_m-i);
    }
    cout << countOfVars;
	return 0;
}
