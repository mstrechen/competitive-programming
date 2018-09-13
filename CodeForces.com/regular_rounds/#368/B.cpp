
#include<iostream>
#include<vector>

using namespace std;

const int INF = 1000000009;

vector<int> connected[100500], cost[100500];
bool isBad[100500];


int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    int tmp1, tmp2, tmp3;
    cin >> n >> m >> k;
    for(int i = 0; i<m; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        connected[tmp1].push_back(tmp2);
        connected[tmp2].push_back(tmp1);
        cost[tmp1].push_back(tmp3);
        cost[tmp2].push_back(tmp3);
    }
    for(int i = 0; i<k; i++)
    {
        cin >> tmp1;
        isBad[tmp1] = 1;
    }

    int lowCost = INF;

    for(int i = 1; i<=n; i++)
    {
        if(isBad[i])
        {
            for(int j = 0; j<connected[i].size(); j++)
            {
                if((!isBad[connected[i][j]])&&(cost[i][j]<lowCost))
                    lowCost = cost[i][j];
            }
        }
    }
    if(lowCost==INF)
        cout << -1;
    else
        cout << lowCost;

    return 0;
}
