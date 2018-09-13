#include<iostream>


using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;

    if(n==0)
    {
        cout << "0 1 2";
    }
    else
    if(n == 1 || n == -1)
    {
        cout << "0 0 0";
    }
    else
    {
        cout << "-1 1 " << -n;
    }

    return 0;
}
