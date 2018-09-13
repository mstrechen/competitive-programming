#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int countOfNumbers;
    cin >> countOfNumbers;

    vector<int> sequence(countOfNumbers);
    vector<vector<pair<long long,long long> > > dp(countOfNumbers, vector<pair<long long,long long> >(countOfNumbers,make_pair(0,0)));

    for(int i = 0; i<countOfNumbers; i++)
    {
        cin >> sequence[i];
        dp[i][i] = {sequence[i],0};
    }


    for(int i = countOfNumbers-2; i>=0; i--)
        for(int j = i+1; j<countOfNumbers; j++)
        {
            pair<long long,long long>firstChoice = {dp[i][j-1].second+sequence[j], dp[i][j-1].first},
                        secondChoice = {dp[i+1][j].second+sequence[i], dp[i+1][j].first};

            if(firstChoice.first-firstChoice.second>secondChoice.first-secondChoice.second)
                dp[i][j] = firstChoice;
            else
                dp[i][j] = secondChoice;
        }



    cout << (dp[0][countOfNumbers-1].first);

    return 0;
}
