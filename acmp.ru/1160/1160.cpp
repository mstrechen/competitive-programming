#include<iostream>
#include<vector>

using namespace std;

vector<int> piFunction(const string & s)
{
    vector<int> pi(s.size());
    pi[0] = 0;
    for(int i = 1; i<(int)pi.size(); i++)
    {
        int cur = pi[i-1];
        while(cur!=0 && s[i]!=s[cur])
            cur = pi[cur-1];

        if(s[i]==s[cur])
            pi[i] = cur+1;
        else
            pi[i] = cur;
    }
    return pi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> s;

    vector<int> pi  = piFunction(s);

    for(auto i : pi)
        cout << i << ' ';

    return 0;
}
