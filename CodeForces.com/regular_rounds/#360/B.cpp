#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 200000;

pair<int,int> e[MAXN];

vector<int> A[MAXN];
int color[MAXN];


queue<pair<int, int> > q;
vector<int> res1, res2;
int main()
{
  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  for(int i = 0; i<m; i++)
  {
    cin >> e[i].first >> e[i].second;
    e[i].first--;
    e[i].second--;
    A[e[i].first].push_back(e[i].second);
    A[e[i].second].push_back(e[i].first);
  }
  for(int _i = 0; _i<n; _i++)
  {
    if(color[_i]==0)
    {
      q.push({_i,1});
      while(!q.empty())
      {
        int curr = q.front().first;
        int c = q.front().second;
        color[curr] = c;
        q.pop();
        for(int i = 0; i<A[curr].size(); i++)
        {
          if(color[A[curr][i]])
          {
            if(color[A[curr][i]]==color[curr])
            {
              cout << -1;
              return 0;
            }
          }
          else
          {
            q.push({A[curr][i], -c});
          }
        }
      }
    }
  }
  for(int i = 0; i<n; i++)
  {
    if(color[i]==1)
    {
      res1.push_back(i+1);
    }
    else
    {
      res2.push_back(i+1);
    }
  }
  cout << res1.size() << '\n';
  for(int i = 0; i<res1.size(); i++)
  {
    cout << res1[i] << ' ';
  }
  cout << '\n';
  cout << res2.size() << '\n';
  for(int i = 0; i<res2.size(); i++)
  {
    cout << res2[i] << ' ';
  }

  return 0;
}
