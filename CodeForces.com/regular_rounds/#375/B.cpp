#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    cin >> n >> s;
    s = "_"+s+"_";
    int countOfOpened = 0;
    int countOfWordsInside = 0;
    int maxWord = 0;
    int currentWord = 0;
    for(int i = 1; i<s.size(); i++)
    {
        if(s[i]=='_'||s[i]==')'||s[i]=='(')
        {
            if(countOfOpened==0&&currentWord>maxWord)
                maxWord = currentWord;
            currentWord = 0;

            if(s[i]=='(')
            {
                countOfOpened++;
            }
            else
            if(s[i]==')')
            {
                countOfOpened--;
            }
        }
        else
        {
            if(currentWord==0&&countOfOpened)
                countOfWordsInside++;
            currentWord++;
        }


    }
    cout << maxWord << ' ' << countOfWordsInside;

    return 0;
}
