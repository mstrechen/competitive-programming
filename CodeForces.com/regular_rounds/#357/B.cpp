#include<iostream>
#include<string>

using namespace std;

long long h = 1234567;
long long d = 123456;
long long c = 1234;
int main()
{
    ios::sync_with_stdio(false);

    long long a;
    cin >> a;

    for(long long i = 0; i<=a/h; i++)
        for(long long j = 0; j<=(a-h*i)/d; j++)
            if((a-i*h-j*d)%c==0)
        {
                cout << "YES";
                return 0;
        }

    cout << "NO";

    return 0;
}
