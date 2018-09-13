#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<string>

using namespace std;

struct comp
{
    bool operator ()(const pair<char, int> & a, const pair<char, int> & b)
    {
        if(a.first!=b.first)
            return a.first<b.first;
        return a.second>b.second;
    }
};

int counts[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    map<char, int> sres;
    int m;

    cin >> m;

    cin >> s;

    for(auto i:s)
        counts[i-'a']++;

    int n = s.size();
    s.append(100500,(char)(255));

    if(m>n)
    {
        char c = 255;
        for(auto i : s)
            c = min(c,i);
        cout << c;
    }
    else
    {
        pair<char, int> cRes = {'z'+1, m};
        for(int i = m-1; i>=0; i--)
        {
            if(cRes.first>s[i])
            {
                cRes = {s[i], i};
            }
        }
        sres[cRes.first]++;

        set<pair<char, int>, comp> setOfLetters;

        int currI = cRes.second+m;
        int DELTA = m;

        for(int i = currI-m; i<currI; i++)
            setOfLetters.insert({s[i], i});

        for(int i = currI; i<n; i++)
        {
            setOfLetters.insert({s[i],i});
            setOfLetters.erase({s[i-DELTA],i-DELTA});
            if(i==currI)
            {
                sres[setOfLetters.begin()->first]++;
                currI = setOfLetters.begin()->second+m;
            }
        }


        auto lastIt = sres.end();

        lastIt--;
        char lastChar = lastIt->first;

        for(char i = 'a'; i<lastChar; i++)
        {
            cout << string(counts[i-'a'], i);
        }
        cout << string(lastIt->second, lastIt->first);
    }



    return 0;
}
