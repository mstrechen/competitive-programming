#include<iostream>
#include<vector>
#include<set>
#include<cassert>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,m,k;
    cin >> n >> m >> k;

    vector<vector<int> > canTakeQuestion(n+2, vector<int>(m,0));

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
        {
            char x;
            cin >> x;
            canTakeQuestion[i][j] = (x=='1');
        }

    for(int i = n-1; i>=0; i--)
        for(int j = 0; j<m; j++)
        if(canTakeQuestion[i][j])
        {
            canTakeQuestion[i][j]+=canTakeQuestion[i+1][j];
        }


    set<pair<int,int> > playersInTeam;
    set<int> players;

    for(int i = 0; i<m; i++)
    {
        playersInTeam.insert({canTakeQuestion[0][i], i});
    }

    auto it = playersInTeam.rbegin();

    for(int i = 0; i<k; i++)
    {
        players.insert(it->second);
        it++;
    }

    for(int i = 0; i<=n; i++)
    {
        int minQI = *players.begin();

        for(auto j : players)
        {
            if(canTakeQuestion[i][j]==0)
            {
                cout << i;
                return 0;
            }
            if(canTakeQuestion[i+1][j]<canTakeQuestion[i+1][minQI])
                minQI = j;
        }

        int maxQI = -1;
        for(int j = 0; j<m; j++)
            if(!players.count(j))
            {
                if(maxQI == -1)
                    maxQI = j;
                else
                if(canTakeQuestion[i+1][maxQI]<canTakeQuestion[i+1][j])
                    maxQI = j;
            }


        if(maxQI!=-1 && canTakeQuestion[i+1][maxQI]>canTakeQuestion[i+1][minQI])
        {
            players.erase(minQI);
            players.insert(maxQI);
        }
        assert(players.size()==k);
    }



    return 0;
}

