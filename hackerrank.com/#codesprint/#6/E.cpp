#include<iostream>
#include<bitset>
#include<vector>
#include<set>

using namespace std;

long long a[100000];

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int _i = 0; _i<t; _i++)
    {
        long long b,n,k, summ;
        cin >> n >> k >> b;
        summ = n-b*(b+1)/2;

        if(summ<0)
        {
            cout << -1;
        }
        else
        {
            for(int i = 0; i<b; i++)
                a[i] = i+1;
            for(int i = b-1; i>=0; i--)
            {
               long long  tmp = min(summ,k-b);
                summ-=tmp;
                a[i]+=tmp;
            }
            if(!summ)
            {
                for(int i = 0; i<b; i++)
                    cout << a[i] << ' ';
            }
            else
            {
                cout << -1;
            }
        }


        cout << '\n';
    }

    return 0;
}
