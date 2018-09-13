#include<iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    cout << 1 + ((n%2)||(n==2));

    return 0;
}
