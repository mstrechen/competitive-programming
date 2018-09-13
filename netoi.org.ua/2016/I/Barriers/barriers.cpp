#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a&&b)
        return gcd(b%a, a);
    return a+b;
}

int lcm(int a, int b)
{
    return a*b/gcd(a,b);
}

int lcm(int a, int b, int c)
{
    return lcm(a,lcm(b,c));
}


int main()
{
    ios::sync_with_stdio(false);

    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;

    n1++;
    n2++;
    n3++;

    int resAll = lcm(n1,n2,n3)-1;
    int res1 = resAll/n1 + resAll/lcm(n2,n3) - resAll/lcm(n1,n2) - resAll/lcm(n1,n3);
    int res2 = resAll/n2 + resAll/lcm(n1,n3) - resAll/lcm(n1,n2) - resAll/lcm(n2,n3);
    int res3 = resAll/n3 + resAll/lcm(n1,n2) - resAll/lcm(n1,n3) - resAll/lcm(n2,n3);


    cout << resAll << ' ' << res1 << ' ' << res2 << ' ' << res3;


    return 0;
}
