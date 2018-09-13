#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b, c;

    cin >> a >> b;

    int n;
    cin >> n;

    cout << a << ' ' << b << '\n';
    for(int i = 0; i<n; i++)
    {
        cin >> c;
        if(c==a)
            cin >> a;
        else
            cin >> b;

        cout << a << ' ' << b << '\n';
    }

    return 0;
}
