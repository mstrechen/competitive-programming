#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int oo = 2*1000*1000*1000;

const double NO_ANS = -1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int playersCount, minTeam, countOfTeams;

    cin >> playersCount >> minTeam >> countOfTeams;

    vector<long long> players(playersCount+1, 0);

    for(int i = 1; i<=playersCount; i++)
    {
        cin >> players[i];
        players[i]+=players[i-1];
    }

    vector<vector<pair<float,int> > > dp(playersCount+1, vector<pair<float,int> >(countOfTeams+1, make_pair(0, NO_ANS)));

    dp[0][0] = {+oo, 0};

    for(int i = 1; i<=playersCount; i++)
    {
        for(int j = 1; j<=countOfTeams; j++)
        if( j + (playersCount-i)/minTeam >=countOfTeams && j*minTeam <= i )
        {
            for(int k = minTeam; k<=i; k++)
            {
                dp[i][j] = max(dp[i][j],{ min(dp[i-k][j-1].first, (players[i] - players[i-k])*1.0F/k), k});
            }
        }

    }


    vector<int> ans;
    for(int i = playersCount, j = countOfTeams; j>0;)
    {
        ans.push_back(dp[i][j].second);
        i-=dp[i][j].second;
        j--;
    }

    for(auto it = ans.rbegin(); it!=ans.rend(); it++)
        cout << *it << ' ';


    return 0;
}

