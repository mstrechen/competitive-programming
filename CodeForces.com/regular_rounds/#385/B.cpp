#include<iostream>
#include<vector>
#include<string>

using namespace std;


bool check(string & s)
{
    int prev = -1;

    for(int i = 0; i<(int)s.size(); i++)
    {
        if(s[i]=='X')
            if(prev==-1)
            {
                prev = i;
            }
            else
            {
                if(prev!=i-1)
                    return 1;
                prev = i;
            }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<string> s(n);

    string good(m,'.');

    for(auto & i : s)
        cin >> i;

    int prev = -1;

    for(int i = 0; i<n; i++)
    {
        if(s[i]!=good)
        {
            if(prev==-1)
            {
                if(check(s[i]))
                {
                    cout << "NO";
                    return 0;
                }
            }
            else
                if(prev!=i-1||check(s[i])||s[i]!=s[i-1])
                {
                    cout << "NO";
                    return 0;
                }
           prev = i;

        }
    }

    if(prev==-1)
        cout << "NO";
    else
        cout << "YES";


    return 0;
}
