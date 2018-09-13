#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;

    vector<int> black;
    cin >> s;
    s+='_';
    int curr = 0;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]=='B')
            curr++;
        else
        {
            if(curr)
                black.push_back(curr);
            curr = 0;
        }
    }
    cout << black.size() << '\n';
    for(auto i: black)
        cout << i << ' ';

    return 0;
}
