#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1e5+500;


long long _max(long long a, long long b)
{
  return a>b?a:b;
}
struct node
{
  vector<int> e;
  long long dp[2];
  long long mass;
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
  long long maxSumm = 0, maxSummIncludeThis = _tree[_i].mass;
  for(int i = 0; i<_tree[_i].e.size(); i++)
  {
    if(!visited[_tree[_i].e[i]])
    {
      DFS(_tree[_i].e[i]);
      maxSumm+=_max(_tree[_tree[_i].e[i]].dp[0], _tree[_tree[_i].e[i]].dp[1]);
      maxSummIncludeThis+=_tree[_tree[_i].e[i]].dp[0];
    }
  }
  _tree[_i].dp[0] = maxSumm;
  _tree[_i].dp[1] = maxSummIncludeThis;
}

int main()
{
  ios::sync_with_stdio(false);
  int n;
  long long  tmp1, tmp2;
  cin >> n;
  for(int i = 1; i<n; i++)
  {
    cin >> tmp1 >> tmp2;
    --tmp1;
    --tmp2;
    _tree[tmp1].e.push_back(tmp2);
    _tree[tmp2].e.push_back(tmp1);
  }
  for(int i = 0; i<n; i++)
    cin >> _tree[i].mass;

  DFS(0);
  cout << _max(_tree[0].dp[0],_tree[0].dp[1]);
  return 0;
}
