#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1e5+500;
const long long MINF = -1e18;

long long _max(long long a, long long b)
{
  return a>b?a:b;
}
struct node
{
  vector<pair<int, int> > e;
  long long dp[2];
  node(long long  a = 0, long long b = 0)
  {
    this->dp[0] = a;
    this->dp[1] = b;
  }

} _tree[MAXN];
bool visited[MAXN];

void DFS(int _i)
{
  visited[_i] = 1;
  long long maxSumm = 0, minCost = MINF;

  for(int i = 0; i<_tree[_i].e.size(); i++)
  {
    if(!visited[_tree[_i].e[i].first])
    {
      DFS(_tree[_i].e[i].first);
      maxSumm+=max(_tree[_tree[_i].e[i].first].dp[0], _tree[_tree[_i].e[i].first].dp[1]);

       minCost = max(minCost,
                    _tree[_i].e[i].second -
                    max(_tree[_tree[_i].e[i].first].dp[0], _tree[_tree[_i].e[i].first].dp[1])+
                    _tree[_tree[_i].e[i].first].dp[0]);
    }
  }
  _tree[_i].dp[0] = maxSumm;
  if(minCost==MINF)
    _tree[_i].dp[1] = 0;
  else
    _tree[_i].dp[1] = maxSumm + minCost;
}

int main()
{
  ios::sync_with_stdio(false);
  int n;
  long long  tmp1, tmp2, tmp3;
  cin >> n;
  for(int i = 1; i<n; i++)
  {
    cin >> tmp1 >> tmp2 >> tmp3;
    --tmp1;
    --tmp2;
    _tree[tmp1].e.push_back(make_pair(tmp2,tmp3));
    _tree[tmp2].e.push_back(make_pair(tmp1,tmp3));
  }

  DFS(0);
  cout << _max(_tree[0].dp[0],_tree[0].dp[1 ]);
  return 0;
}
