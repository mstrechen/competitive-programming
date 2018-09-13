#include<iostream>
#include<string>

using namespace std;

void remake(string s)
{
    bool isJava = 0, isCpp = 0;
    for(int i = 0; i<s.length(); i++)
    {
        isJava|=(s[i]>='A')&&(s[i]<='Z');
        isCpp|=s[i]=='_';
    }
    if((isJava&&isCpp)||s[0]=='_'||((s[0]>='A')&&(s[0]<='Z')))
    {
        cout << "Error!";
    }
    else
    if(isCpp)
    {
        isCpp = (s[s.length()-1]=='_');
        for(int i = 0; i<s.length()-1; i++)
            isCpp|=(s[i]=='_'&&s[i+1]=='_');
        if(isCpp)
        {
            cout << "Error!";
        }
        else
        {
            isCpp = 0;
            for(int i = 0; i<s.length(); i++)
            {
                if(s[i]=='_')
                {
                    isCpp = 1;
                }
                else
                {
                    if(isCpp)
                    {
                        isCpp = 0;
                        cout << (char)(s[i]-'a'+'A');
                    }
                    else
                    {
                        cout << s[i];
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
                cout << '_' << (char)(s[i]-'A'+'a');
            else
                cout << s[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    remake(s);
    return 0;
}
