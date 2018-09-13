#include<iostream>

using namespace std;


int getSumOfDigits(int n)
{
    int res = 0;
    while(n>0)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);

	int n;

    cin >> n;

    for(int i = 1; i<=100; i++)
        if(getSumOfDigits(i*n)*n == i*n)
        {
            cout << i*n;
            return 0;
        }
    cout << 0;

    return 0;
}
