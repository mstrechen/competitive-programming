#include<iostream>

using namespace std;


long long _abs(long long a)
{
    return a>0?a:-a;
}


long long vecMul(long long x1,long long y1,long long x2,long long y2)
{
    return _abs(x1*y2-x2*y1);
}
long long x[100001], y[100001];
int main()
{
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    long long maxSize = 2000000000;
    maxSize*=1000000000;
    long long a = 0, b = 1;
    for(long long i = 0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for(long long i = 0; i<n; i++)
        for(long long j = i+1; j<n; j++)
        {
            long long tmp = vecMul(x[i],y[i],x[j],y[j]);
            if(tmp&&tmp<maxSize)
            {
                maxSize = tmp;
                a = i;
                b = j;
            }
        }
    cout << a+1 << ' ' << b+1;
    return 0;
}
