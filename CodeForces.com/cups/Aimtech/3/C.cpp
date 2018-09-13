#include<iostream>

using namespace std;


char change(char c)
{
    if(c>'a')
        return (c-1);
    return 'z';
}

int main()
{
    ios::sync_with_stdio(false);

    string s;

    cin >> s;

    int l = s.size()-1, r = s.size()-1;
    bool flag = 1;

    for(int i = 0; flag&&i<s.size(); i++)
    {
        if(s[i]!='a')
        {
            l = i;
            flag = 0;
        }
    }
    r = l;
    flag = 1;
    for(int i = l+1; flag&&i<s.size(); i++)
    {
        if(s[i]=='a')
        {
            r = i-1;
            flag = 0;
        }
    }
    if(flag)
        r = s.size()-1;
    for(int i = 0; i<s.size(); i++)
    {
        if(l<=i&&i<=r)
            cout << change(s[i]);
        else
            cout << s[i];
    }


    return 0;
}
