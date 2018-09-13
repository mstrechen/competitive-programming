#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

const int MAXN = 200500;

map<int,int> colorsToCounts;
set<pair<int,int> >countsToColors;

vector<int> g[MAXN];
int a[MAXN];
bool used[MAXN];



int DFS(int _i)
{
    int res = 1;
    int color = a[_i];
    pair<int, int> tmp = {colorsToCounts[color], color};
    colorsToCounts[color]++;
    countsToColors.erase(tmp);
    tmp.first++;
    countsToColors.insert(tmp);
    used[_i] = 1;


    for(int i = 0; i<g[_i].size(); i++)
    if(!used[g[_i][i]])
    {
        res+=DFS(g[_i][i]);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;

    cin >> n >> m >> k;

    for(int i = 0; i<n; i++)
        cin >> a[i];
    int tmp1, tmp2;
    for(int  i = 0; i<m; i++)
    {
        cin >> tmp1 >> tmp2;
        g[tmp1-1].push_back(tmp2-1);
        g[tmp2-1].push_back(tmp1-1);
    }
    int answer = 0;
    for(int i = 0; i<n; i++)
    {
        if((!used[i])&&(g[i].size()))
        {
            colorsToCounts.clear();
            countsToColors.clear();
            int tmp = DFS(i);
            answer+=tmp-countsToColors.rbegin()->first;
        }
    }
    cout << answer;
    return 0;
}
