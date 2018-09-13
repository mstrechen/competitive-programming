#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long n, m, x, y;

    cin >> n >> m >> x >> y;

    long long dist = min(min(x, y), min(n - x + 1, m - y + 1));

    long long ans = (dist*2 - 1)*(dist*2 - 1);

    if(x+dist-1 == n){}
    else if(y == dist){ans+=dist*2 - 1;}
    else if(x == dist){ans+=dist*2 - 1;
                       ans+=dist*2;}
    else{ans+=dist*2 - 1;
         ans+=dist*2;
         ans+=dist*2;}

    cout << ans;

    return 0;
}
