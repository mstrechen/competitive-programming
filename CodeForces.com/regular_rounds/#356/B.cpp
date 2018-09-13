#include<iostream>
#include<algorithm>

using namespace std;

int a[100];
int main()
{
    ios::sync_with_stdio(false);
    int n,k,l, summ = 0;
    cin >> n >> k;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    k--;
    summ+=a[k];
    for(int i = 1; i<100; i++)
    {
        if(k-i>=0&&k+i<n)
        {
            summ+=(a[k-i]&a[k+i])*2;
        }
        else
        {
            if(k-i>=0)
                summ+=a[k-i];
            if(k+i<n)
                summ+=a[k+i];
        }
    }

    cout << summ;

    return 0;
}
