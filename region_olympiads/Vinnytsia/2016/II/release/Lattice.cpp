#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;


    unsigned long long summ = 0;

    if(n>m)
        swap(n,m);

    n++;
    m++;

    for(long long i = 1; i<n; i++)
    {
        summ+=(n-i)*(m-i)*i;
    }

    cout << summ;


    return 0;
}
