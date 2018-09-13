#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream cout("inp.txt");
    for(int i = 1; i<=3; i++)
    {
        for(int a = 1; a<=3; a++)
            for(int b = 1; b<=3; b++)
            {
                if(i == 1)
                {
                    cout << i << a << b << ' ';
                    cout << 1 << a << b << '\n';
                    cout << i << a << b << ' ';
                    cout << 2 << a << b << '\n';
                    cout << i << a << b << ' ';
                    cout << 3 << a << b << '\n';
                    cout << i << b << a << ' ';
                    cout << 1 << b << a << '\n';
                    cout << i << b << a << ' ';
                    cout << 2 << b << a << '\n';
                    cout << i << b << a << ' ';
                    cout << 3 << b << a << '\n';
                }
                else
                if(i == 2)
                {
                    cout << i << a << b << ' ';
                    cout << a << 1 << b << '\n';
                    cout << i << a << b << ' ';
                    cout << a << 2 << b << '\n';
                    cout << i << a << b << ' ';
                    cout << a << 3 << b << '\n';
                    cout << i << b << a << ' ';
                    cout << b << 1 << a << '\n';
                    cout << i << b << a << ' ';
                    cout << b << 2 << a << '\n';
                    cout << i << b << a << ' ';
                    cout << b << 3 << a << '\n';
                }
                else
                {
                    cout << i << a << b << ' ';
                    cout << a << b << 1 << '\n';
                    cout << i << a << b << ' ';
                    cout << a << b << 2 << '\n';
                    cout << i << a << b << ' ';
                    cout << a << b << 3 << '\n';
                    cout << i << b << a << ' ';
                    cout << b << a << 1 << '\n';
                    cout << i << b << a << ' ';
                    cout << b << a << 2 << '\n';
                    cout << i << b << a << ' ';
                    cout << b << a << 3 << '\n';

                }
            }
    }
    cout << "$";

    return 0;
}
