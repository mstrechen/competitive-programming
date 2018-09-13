#include<iostream>

using namespace std;
int a[50000];
int main()
{
    int n,k, wrong = -1,summ;

    cin >> n >> k;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    n/=k;
    for(int i = 0; i<k; i++)
    {
        summ = 0;
        for(int j = 0; j<n; j++)
        {
            summ+=a[i*n+j];
        }
        if(0<=summ&&summ<=n)
        {

        }
        else
        {
            if(summ==1z)
            {
                for(int j = 0; j<n)
            }
        }
    }
    if(wrong==100500)
        cout << "FAIL";
    else
        cout << "OK\n" << wrong+1;

    return 0;
}
