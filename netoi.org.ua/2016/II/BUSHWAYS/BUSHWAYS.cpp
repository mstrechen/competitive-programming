#include<iostream>

using namespace std;

unsigned long long solve2(int depth)
{
    unsigned long long dp[19];

    dp[1] = 1;

    unsigned long long currentCount = 2;
    for(int i = 2; i<=depth; i++)
    {
        currentCount*=(i+1);
        dp[i] = dp[i-1] + currentCount + (currentCount/2)*i;
    }
    return dp[depth];
}

unsigned long long solve3(int depth)
{
    unsigned long long dp[19];

    dp[1] = 0;
    dp[2] = 6;

    unsigned long long currentCount = 6;
    for(int i = 3; i<=depth; i++)
    {
        currentCount*=(i+1);
        dp[i] = dp[i-1] + currentCount + currentCount*(i-1);
    }

    return dp[depth];
}

int main()
{
    int len, depth;
    cin >> len >> depth;


    if(len==2)
        cout << solve2(depth);
    else
        cout << solve3(depth);

    return 0;
}
