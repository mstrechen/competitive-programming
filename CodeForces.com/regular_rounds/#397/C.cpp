#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, a, b;

    cin >> k >> a >> b;

    if ((a % k == 0 && a != 0) || (b % k == 0 && b != 0))
    {
        cout << a/k + b/k;
        return 0;
    }

    if ((a < k && b%k != 0) || (b < k && a%k != 0))
    {
        cout << -1;
        return 0;
    }

    cout << a/k + b/k;



    return 0;
}
