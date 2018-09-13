#include<iostream>

using namespace std;

long long _abs(long long a)
{
    return a>0?a:-a;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    long long a,b,c, _a, _b, current;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> a >> b >> c;
        _a = (a*b)/(c*c);
        if(_a==0)
            current = c*c;
        else
            if(_abs(a*b-_a*c*c)<_abs(a*b-(_a+1)*c*c))
                current = _a*c*c;
            else
                current = (_a+1)*c*c;

        cout << current << '\n';
    }
    return 0;
}
