#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 0;

    while(n)
    {
        cnt++;
        n/=2;
    }

    cout << cnt;

    return 0;
}
