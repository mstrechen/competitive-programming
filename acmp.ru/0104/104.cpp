#include<iostream>
#include<string>
#include<vector>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sToCheck,sTemplate;

    cin >> sToCheck >> sTemplate;

    if(sToCheck.find('?')!=string::npos||sToCheck.find('*')!=string::npos)
        swap(sToCheck, sTemplate);

    vector<vector<char>> dp(sTemplate.size()+1, vector<char>(sToCheck.size()+1, 0));
    dp[0][0]=1;


    for(int i = 1; i<=sTemplate.size(); i++)
    {
        for(int j = 0; j<=sToCheck.size(); j++)
        {
            if(j>0)
            {
                if(sTemplate[i-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else
                if(sTemplate[i-1]==sToCheck[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                if(sTemplate[i-1] == '*')
                    for(int k = 0; k<=j; k++)
                        dp[i][j]|=dp[i-1][k];
            }
            else
            if(sTemplate[i-1]=='*')
                dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[sTemplate.size()][sToCheck.size()])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
