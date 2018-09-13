#include<iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n==0)
        cout << 3;
    else
    {
        string eAfter = "71828182845904523536028750";
        cout << 2 << '.';
        if(eAfter[n]<'5')
            cout << string(eAfter.begin(),eAfter.begin()+n);
        else
            cout << string(eAfter.begin(),eAfter.begin()+n-1) << (char)(eAfter[n-1]+1);
    }

    return 0;
}
