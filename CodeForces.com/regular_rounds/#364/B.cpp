#include<iostream>

using namespace std;

int h[100500], w[100500];
int main()
{
    ios::sync_with_stdio(false);
    long long n, m;

    long long ans = 0;
    long long fullW = 0, fullH = 0;
    int x,y;
    cin >> n >> m;
    for(int i = 0; i<m; i++)
    {
        cin >> x>> y;
        if(h[x]==0)
        {
            h[x] = 1;
            fullH++;
        }
        if(w[y]==0)
        {
            w[y] = 1;
            fullW++;
        }
        cout << ((long long)n-fullW)*(n-fullH) << ' ';
    }



    return 0;
}
