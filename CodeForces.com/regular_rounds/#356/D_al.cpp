#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>

using namespace std;

long long a[19] = {1, 2, 3, 4, 5,
            6, 7, 15, 23, 50,
             114, 330, 1330, 10591, 215970,
             19464802, 16542386125, 409477218238718,1000000000000001};
int main()
{
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    long long * _b = upper_bound(a,a+19,n);
    cout << (_b - a) << ' ' << *(_b-1);

    return 0;
}

