#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, r;
    cin >> k >> r;
    int t = k, i = 1;
    while(t%10!=r&&t%10!=0)
    {
        t+=k;
        i++;
    }
    cout << i;

    return 0;
}
