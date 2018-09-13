#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ofstream cout("inp.txt");

    int n = 100;
    int m = 100;
    int k = 100;
    cout << n << ' ' << m << ' ' << k << '\n';
    for(int i = 0; i<n; i++)
    {
        cout << 0 << ' ';
    }
    for(int i = 0; i<n; i++)
    {
        for(int i = 0; i<n; i++)
            cout << rand()%100 << ' ';
        cout << endl;
    }

    return 0;
}
