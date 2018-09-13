#include<iostream>
#include<fstream>

using namespace std;

long long dyn[1001][1001];

long long min(long long a, long long b)
{
    return a<b?a:b;
}
long long abs(long long a)
{
    return a>0?a:-a;
}

int a[1000];
int prefixS[1000];

int main()
{
    ios::sync_with_stdio(false);
    ifstream cin("wall.in");
    ofstream cout("wall.out");
    int n;
    int BIG, SMALL, summ, countOfBig;

    cin >> n;

    for(int i = 1; i<=n; i++)
        for(int j = 0; j<=n; j++)
            dyn[i][j] = 1e17;

    for(int i = 0; i<n; i++)
        cin >> a[i];

    prefixS[0] = a[0];
    for(int i = 1; i<n; i++)
        prefixS[i] = prefixS[i-1]+a[i];

    SMALL = prefixS[n-1]/n;
    countOfBig = prefixS[n-1]%n;

    BIG = SMALL+1;

    for(int i = 0; i<n; i++)
        for(int j = 0; j<=i; j++)
        {
            dyn[i+1][j] = min(dyn[i+1][j],dyn[i][j]+abs(prefixS[i]-BIG*(i-j+1)-SMALL*(j)));
            dyn[i+1][j+1] = min(dyn[i+1][j+1],dyn[i][j]+abs(prefixS[i]-BIG*(i-j)-SMALL*(j+1)));
        }
    cout << dyn[n][n-countOfBig];
    return 0;
}
