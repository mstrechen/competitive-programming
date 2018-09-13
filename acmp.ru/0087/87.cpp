#include<iostream>
#include<set>
#include<string>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> ss;
    do
    {
        ss.push_back("");
        getline(cin, ss[ss.size()-1]);
    }
    while(ss[ss.size()-1]!="ENDOFINPUT");

    ss.pop_back();
    set<string> poss;

    for(auto i : ss)
        poss.insert(i);

    int ans = 0;
    for(auto s : ss)
    {
        bool flag = 1;
        for(int i = 1; flag&&i<s.size(); i++)
        {
            if(poss.count(string(s.begin(), s.begin()+i))&&
               poss.count(string(s.begin()+i, s.end())))
            {
                ans++;
                flag = 0;
            }
        }
    }
    cout << ans;

    return 0;
}
