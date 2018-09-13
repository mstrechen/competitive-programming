#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char a1, a2, a3, a4;
    int n;
    cin >> n;
    string a;
    cin >> a;

    if(n==12)
    {
        if(a[0]>'1'||(a[0]=='1'&&a[1]>'2'))
            a[0] = '0';
        if(a[0]=='0'&&a[1]=='0')
            a[0] = '1';
    }
    else
    {
       if(a[0]>'2'||(a[0]=='2'&&a[1]>'3'))
            a[0] = '0';
    }

    if(a[3]>'5')
        a[3] = '0';

    cout << a;

    return 0;
}
