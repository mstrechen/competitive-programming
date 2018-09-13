#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int countOfNumbers;
    cin >> countOfNumbers;

    vector<int> sequence(countOfNumbers);
    vector<vector<pair<int,int> > > dp(countOfNumbers, vector<pair<int,int> >(countOfNumbers,make_pair(0,0)));

    for(int i = 0; i<countOfNumbers; i++)
    {
        cin >> sequence[i];
        dp[i][i] = {sequence[i],0};
    }


    for(int i = countOfNumbers-2; i>=0; i--)
        for(int j = i+1; j<countOfNumbers; j++)
        {
            pair<int,int>firstChoice = {dp[i][j-1].second+sequence[j], dp[i][j-1].first},
                        secondChoice = {dp[i+1][j].second+sequence[i], dp[i+1][j].first};

            if(firstChoice.first-firstChoice.second>secondChoice.first-secondChoice.second)
                dp[i][j] = firstChoice;
            else
                dp[i][j] = secondChoice;
        }


    if(dp[0][countOfNumbers-1].first == dp[0][countOfNumbers-1].second)
        cout << 0;
    else
        cout << 1+(dp[0][countOfNumbers-1].first<dp[0][countOfNumbers-1].second);


    return 0;
}
