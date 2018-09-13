#include<iostream>
#include<sstream>

using namespace std;

int getCount(string & s)
{
    int ans = 0;
    for(auto i:s)
        ans+=(i=='a')||(i=='e')||(i=='i')||(i=='o')||(i=='u')||(i=='y');
    return ans;
}

int a[101];
int p[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;


    cin >> n;



    for(int i =0; i<n; i++)
    {
        cin >> p[i];
    }
    getline(cin,s);
    for(int i = 0; i<n; i++)
    {
        getline(cin, s);
        if(p[i]!=getCount(s))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
