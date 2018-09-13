#include<iostream>

using namespace std;

int a[200500];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool flag = 1;

    for(int i = 0; i<n; i++)
        cin >> a[i];

    for(int i = 0; flag&&i+1<n; i++)
    {
        if(a[i]%2)
        {
            if(a[i+1])
            {
                a[i+1]--;
                a[i]--;
            }
            else
            flag = 0;
        }
    }
    if(a[n-1]%2)
        flag = 0;
    if(flag)
        cout << "YES";
    else
        cout << "NO";


    return 0;
}
