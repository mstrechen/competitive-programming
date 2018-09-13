#include<iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long i = 62,n;
    long long count = 1;
    cin >> n;
    if(n==0)
    {
        cout << 1;
        return 0;
    }
    while((n>>i)==0)
    {
        i--;
    }
    for(;i>=0; i--)
    {
        count*=1+(((n>>i)&1)==0);
    }
    cout << count;

    return 0;
}
