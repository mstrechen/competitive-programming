#include<iostream>
#include<vector>
#include<string>
#include<cassert>


using namespace std;


int dfs(string & s, int pos, int currLvl, vector<vector<string> > & lvls)
{
    string current;
    while(s[pos]!=',')
    {
        current+=s[pos++];
    }
    pos++;

    if(currLvl>=(int)lvls.size())
        lvls.resize(currLvl+1);

    lvls[currLvl].push_back(current);

    int countOfSons = 0;
    while(pos<(int)s.size()&&s[pos]!=',')
    {
        countOfSons*=10;
        countOfSons+=s[pos++]-'0';
    }
    pos++;

    for(int i = 0; i<countOfSons; i++)
    {
        pos = dfs(s, pos, currLvl+1, lvls);
    }
    return pos;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<string> > allLevels;
    string s;

    cin >> s;

    int pos = 0;
    while(pos<s.size())
    {
        pos = dfs(s, pos, 0,  allLevels);
    }

    cout << allLevels.size() << '\n';
    for(auto & i : allLevels)
    {
        for(auto& j : i)
            cout << j << ' ';
        cout << '\n';
    }


    return 0;
}
