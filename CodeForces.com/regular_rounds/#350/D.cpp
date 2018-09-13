#include <iostream>

using namespace std;


long long a[100000], b[100000];

int n,k;

long long max(long long a, long long b)
{
    if(a>b) return a;
    else return b;
}

bool check(long long j)
{
    long long needed = 0;
    for(int i = 0; i<n; i++)
    {
        if(b[i]<j*a[i])
            needed+= j*a[i] - b[i];
    }
    return (needed<=k);
}

int main(){
	ios::sync_with_stdio(false);
    int maxI = 0;
    cin >> n >> k;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i<n; i++)
    {
        cin >> b[i];
        maxI = max(maxI, (b[i]+k)/a[i]);
    }
    long long l = 0, r = maxI+1;
    while(l+1<r)
    {
        if(check((l+r)/2))
            l = (l+r)/2;
        else
            r = (l+r)/2;
    }
    if(check(r)) cout << r;
    else cout << l;
	return 0;
}
