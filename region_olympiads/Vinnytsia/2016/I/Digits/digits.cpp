#include<iostream>

using namespace std;

bool used[1000][10];
int  modes[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    bool flag = 1;

    int len = 0;
    while(flag)
    {
        flag = 0;
        len++;
        for(int i = 1; i<10; i++)
        {
            used[modes[i]][i] = 1;
            modes[i] = (modes[i]*10 + i)%n;

            if(modes[i]==0)
            {
                cout << i << ' ' << len;
                return 0;
            }
            flag|=!(used[modes[i]][i]);
        }
    }
    cout << 0 << ' ' << 0;


    return 0;
}
