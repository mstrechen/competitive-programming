#include<iostream>

using namespace std;

int a[105];
int main()
{
    ios::sync_with_stdio(false);
    int n,tmp;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    tmp = 0;
    for(int i = 1; i<=100; i++)
        tmp = max(tmp, a[i]);
    cout << n-tmp;
    return 0;
}
