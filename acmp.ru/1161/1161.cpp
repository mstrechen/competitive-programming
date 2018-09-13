#include<iostream>
#include<vector>

using namespace std;

vector<int> zFunction(const string & s)
{
    vector<int> z(s.size());
    z[0] = 0;
    int l = 0, r = 0;
    for(int i = 1; i<(int)z.size(); i++)
    {
        int val = 0;
        if(i<=r)
            val = min(r-i+1, z[i-l]);

        while(i+val < (int)s.size() && s[val] == s[i+val])
            val++;
        z[i] = val;
        if(i + val > r)
        {
            l = i;
            r = i+val-1;
        }
    }
    return z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> s;

    vector<int> z  = zFunction(s);

    for(auto i : z)
        cout << i << ' ';

    return 0;
}
