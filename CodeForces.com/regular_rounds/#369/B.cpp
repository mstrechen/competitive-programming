#include<iostream>

using namespace std;

long long a[1000][1000];

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int i1, j1;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
        {
            cin >> a[i][j];
            if(a[i][j]==0)
            {
                i1 = i;
                j1 = j;
            }

        }
    if(n==1)
    {
        cout << 1;
    }
    else
    {
        long long summ1 = 0, summ2 = 0;
        for(int i = 0; i<n; i++)
        {
            summ1+=a[i1][i];
        }
        int i2;
        if(i1==0)
            i2 = i1+1;
        else
            i2 = i1-1;
        for(int i = 0; i<n; i++)
        {
            summ2+=a[i2][i];
        }
        if(summ2>summ1)
            a[i1][j1] = summ2-summ1;
        else
        {
            cout << -1;
            return 0;
        }
        bool flag = 1;
        long long summ3;
        for(int i = 0; i<n; i++)
        {
            summ3 = 0;
            for(int j = 0; j<n; j++)
            {
                summ3+=a[i][j];
            }
            flag&=(summ3==summ2);
        }
        for(int i = 0; i<n; i++)
        {
            summ3 = 0;
            for(int j = 0; j<n; j++)
            {
                summ3+=a[j][i];
            }
            flag&=(summ3==summ2);
        }
        summ3 = 0;
        for(int j = 0; j<n; j++)
        {
            summ3+=a[j][j];
        }
        flag&=(summ3==summ2);
        summ3 = 0;
        for(int j = 0; j<n; j++)
        {
            summ3+=a[j][n-j-1];
        }
        flag&=(summ3==summ2);
        if(flag)
        {
            cout << a[i1][j1];
        }
        else
        {
            cout << -1;
        }
    }
    return 0;
}
