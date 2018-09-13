#include<iostream>

using namespace std;

int a[200];
int marked[200];
int main()
{
    ios::sync_with_stdio(false);
    int n, summ = 0,tmp;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin>> a[i];
        summ+=a[i];
    }
    summ = summ*2/n;

    for(int i = 0; i<n; i++)
    if(!marked[i])
    {
        for(int j = i+1; j<n; j++)
        {
            if((!marked[j])&&(a[i]+a[j]==summ))
            {
                marked[j] = 1;
                cout << i+1 << ' ' << j+1 << '\n';
                break;
            }
        }
    }
    return 0;
}
