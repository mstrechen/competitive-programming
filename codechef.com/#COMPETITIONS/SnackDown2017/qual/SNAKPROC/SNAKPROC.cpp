#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    int len;
    string in;

    while(q--)
    {
        cin >> len;
        cin >> in;
        int flag = 0;

        for(auto i : in)
        {
            if(i == 'H')
            {
                if(flag & 1)
                {
                    flag = 0b100;
                }
                else
                {
                    flag |= 1;
                }
            }
            else
            if(i == 'T')
            {
                if(flag & 1)
                {
                    flag ^= 1;
                }
                else
                {
                    flag = 0b100;
                }
            }

        }
        if(flag == 0)
        {
            cout << "Valid\n";
        }
        else
        {
            cout << "Invalid\n";
        }
    }

    return 0;
}
