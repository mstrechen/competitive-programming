#include<iostream>
#include<string>
#include<set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> all;

    string s;
    cin >> s;

    for(int i = 0; i<s.size(); i++)
    {
        all.insert(s);
        s =  string(s.begin()+1, s.end())+s[0] ;
    }

    cout << all.size();


    return 0;
}
