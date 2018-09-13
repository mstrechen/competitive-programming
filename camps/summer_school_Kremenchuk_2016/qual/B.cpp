#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream cin("beauty.in");
    ofstream cout("beauty.out");
    int n;
    long long k = 1;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cout << k << '\n';
        k*=3;
    }

    return 0;
}
