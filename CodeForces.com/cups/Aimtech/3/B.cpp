#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int x[100500];


int getDist(int x0, int x1, int X)
{
    if(x0<=X&&X<=x1)
        return x1-x0+min(X-x0, x1-X);

    return max(abs(x1-X), abs(x0-X));

}


int main()
{
    ios::sync_with_stdio(false);

    int n,a;
    cin >> n >> a;
    for(int i = 0; i<n; i++)
        cin >> x[i];

    sort(x, x+n);
    if(n==1)
        cout << 0;
    else
        cout << min(getDist(x[0],x[n-2],a), getDist(x[1],x[n-1],a));
    return 0;
}
