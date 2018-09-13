#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int a[101];
int main()
{
    ios::sync_with_stdio(false);

    a[0] = 1;
    for(int i = 2; i*i<100;i++)
    {
        if(a[i]==0)
        {
            for(int j = 100/i; j>1; j--)
                a[j*i] = 1;
        }
    }
    string ans;
    bool ans2 = 0;
    int num = 0;
    int _j1 = 2, _j2 = 2;

    for(int i = 0; i<20; i++)
    {
        if(num)
        {
            while(a[_j1])
                _j1++;
            if(_j1*num>100)
            {
                    cout << "prime";
                    return 0;
            }
            cout << num*(_j1++) << endl;
            cin >> ans;
            if(ans=="yes")
            {
                cout << "composite" << endl;
                return 0;
            }
        }
        else
        {
            while(a[_j2]==1)
                _j2++;
            cout <<_j2 << endl;
            cin >> ans;
            if(ans =="yes")
                num = _j2;
            _j2++;
        }

    }
    cout << "prime";
    return 0;
}
