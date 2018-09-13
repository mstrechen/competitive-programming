#include<iostream>
#include<string>
#include<vector>
#include<numeric>

using namespace std;


string getAnswer(string s)
{
    s = "#"+s+"#";

    bool flag = 1;
    vector<int> countOfLetters(26,0);
    int countOfSpaces = 0;
    for(int i = 1; i+1<s.size(); i++)
    {
        flag&=s[i]==s[i-1]||s[i]==s[i+1];
        if(s[i]!='_')
            countOfLetters[s[i]-'A']++;
        else
            countOfSpaces++;
    }
    if(flag||(countOfSpaces&&accumulate(countOfLetters.begin(),
                                         countOfLetters.end(), 1,
                                         [](bool a, int b){return a&&(b!=1);}
                                         )))
        return "YES";
    return "NO";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string tmp;
    int tmpI;

    while(n--)
    {
        cin >> tmpI;
        cin >> tmp;
        cout << getAnswer(tmp) << endl;
    }

    return 0;
}
