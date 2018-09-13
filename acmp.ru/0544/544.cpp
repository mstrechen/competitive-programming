#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int countOfStairs;
    cin >> countOfStairs;

    vector<long long> dp(countOfStairs+3, 0);
    dp[0] = 1;

    for(int i = 0; i<countOfStairs; i++)
    {
        dp[i+1]+=dp[i];
        dp[i+2]+=dp[i];
        dp[i+3]+=dp[i];
    }
    cout << dp[countOfStairs];
    return 0;
}
