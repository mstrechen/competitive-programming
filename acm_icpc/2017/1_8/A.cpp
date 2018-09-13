#include<iostream>
#include<cmath>

using namespace std;
double n,p,s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p >> s;
    n=n+(n*p)/100;
    s = (s+1e-9)/n;
    cout << int (floor(s));
    return 0;
}
