#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    s = "a"+s;
    int ans  = 0;
    for(int i = 1; i<s.size(); i++)
    {
        ans+=min(abs(s[i-1]-s[i]), 26-abs(s[i-1]-s[i]));
    }
    cout << ans;
    return 0;
}
