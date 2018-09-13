#include<iostream>
#include<set>
#include<vector>

using namespace std;

int a[10][2] = {{4,2},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}};

set<pair<int, int > > poss = {{4,2},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}};


vector<pair<int,int> >b;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    char c;
    for(int i = 0; i<n; i++)
    {
        cin >> c;
        b.push_back({a[c-'0'][0],a[c-'0'][1]});
    }
    for(int i = -1; i<=1; i++)
        for(int j = -1; j<=1; j++)
        {
            if(i||j)
            {
                bool flag = 1;
                for(int k = 0; k<b.size(); k++)
                {
                    flag&=poss.count({b[k].first+i,b[k].second+j});
                }
                if(flag)
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    cout << "YES";
    return 0;
}
