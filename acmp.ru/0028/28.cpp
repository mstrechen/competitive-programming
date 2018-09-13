#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    vector<int> used(1000, 0);

    cin >> s;

    for(int i = 0; i<(int)s.size(); i++)
        if(s[i]!='0')
            for(int j = i+1; j<(int)s.size(); j++)
                for(int k = j+1; k<(int)s.size(); k++)
                    used[ (s[i]-'0')*100 + (s[j]-'0')*10 + s[k] - '0'] = 1;

    cout << accumulate(used.begin(),used.end(),0);

    return 0;
}
