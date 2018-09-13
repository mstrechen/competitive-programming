#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    unsigned long long a,b,c,d;

    cin >> a >> b >> c >> d;
    a = a>b?b:a;
    c = c>d?d:c;

    a+=c;

    unsigned long long l = 0, r = 2e9;

    while(l+1<r)
    {
        unsigned long long mid = (l+r)/2;
        if(mid*mid>a)
            r = mid;
        else
            l = mid;
    }
    cout << l;

    return 0;
}
