#include<iostream>
#include<vector>
#include<string>
#include<cassert>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int len, maxValue, lenOfAnswer;
    string stringToCheck;

    cin >> len >> maxValue >> lenOfAnswer;
    cin >> stringToCheck;


    unsigned long long modOfAnswer = 1;
    vector<unsigned long long> dp(len+9, 0);

    while(lenOfAnswer--)
        modOfAnswer*=10;
    dp[len] = 1;

    assert(stringToCheck.size()==len);
    for(int i = len-1; i>=0; i--)
    {
        int currentNumber = 0;
        if(stringToCheck[i]=='0')
            dp[i] = dp[i+1];
        else
            for(int j = 0; currentNumber<=maxValue && i+j<len; j++)
            {
                currentNumber*=10;
                currentNumber+=stringToCheck[i+j] - '0';
                if(currentNumber<=maxValue)
                {
                    dp[i]+=dp[i+j+1];
                    dp[i]%=modOfAnswer;
                }
            }
    }

    cout << dp[0];

    return 0;
}
