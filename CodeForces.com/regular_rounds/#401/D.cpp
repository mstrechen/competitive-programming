#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<string> s(n);

    for(auto & i : s)
        cin >> i;

    for(int i = n-1; i>0; i--)
    if(!(s[i-1] < s[i]))
    {
        int firstDif = 0;
        while(firstDif < s[i-1].size() && firstDif < s[i].size() &&
              s[i-1][firstDif] == s[i][firstDif]) firstDif++;
        s[i-1].resize(firstDif);
    }

    for(auto & i : s)
        cout << i << '\n';

    return 0;
}
