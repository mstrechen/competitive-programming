#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);

    for(auto & i : s)
        cin >> i;

    int ans = 0;
    for(int i = 0; i<n; i++)
    for(int j = 1; j<m; j++)
    {
        ans += (s[i][j] == '.') &&(s[i][j-1] == '.');
    }

    for(int i = 1; i<n; i++)
    for(int j = 0; j<m; j++)
    {
        ans += (s[i][j] == '.') &&(s[i-1][j] == '.');
    }

    cout << ans;

    return 0;
}
