#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a[5];
    int summ = 0;
    int maxMinus =0;

    for(int i = 0; i<5; i++)
    {
        cin >> a[i];
        summ+=a[i];
    }
    sort(a,a+5);
    for(int i = 0; i<4; i++)
    {
        if(a[i]==a[i+1])
            maxMinus = max(a[i]+a[i+1], maxMinus);
    }
    for(int i = 0; i<3; i++)
    {
        if(a[i]==a[i+1]&&a[i+1]==a[i+2])
            maxMinus = max(a[i]+a[i+1]+a[i+2], maxMinus);
    }
    cout << summ-maxMinus;

    return 0;
}
