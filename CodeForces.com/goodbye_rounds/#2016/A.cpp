#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int  n, k;

    cin >> n >> k;

    int i = 0;
    int sum = 0;
    while(sum + i*5 <= 240-k)
    {
        sum+=i*5;
        i++;
    }

    cout << min(i-1,n);


    return 0;
}
