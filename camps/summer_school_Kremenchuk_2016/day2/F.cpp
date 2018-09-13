#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1600;


long long _max(long long a, long long b)
{
  return a>b?a:b;
}
struct node
{
  vector<pair<int, int> > e;
  long long dp[400];
  int size;
  int cost;
  node(int a = 1000500)
  {
    this->size = 0;
    for(int i = 1; i<400; i++)
      this->dp[i] = a;
    dp[0] = 0;
  }

}_tree[MAXN];
bool visited[MAXN];
int DFS(int _i, int prevSize, int parent)
{
  visited[_i] = 1;
  _tree[_i].size = 1;
  for(int i = 0; i<_tree[_i].e.size(); i++)
  {
    if(_tree[_i].e[i].first!=parent)
    _tree[_i].size+=DFS(_tree[_i].e[i].first, _tree[_i].e[i].second, _i);
  }
  if(_tree[_i].e.size()==2)
  {
    int a = 0;
    if(_tree[_i].e[0].first==parent)
      a =_tree[_i].e[1].first;
    else
      a = _tree[_i].e[0].first;
    for(int i = 0; i<=100; i++)
      {
          _tree[_i].dp[i] = min(_tree[_i].dp[i],_tree[a].dp[i]);
      }

  }
  else if(_tree[_i].e.size()==3)
  {
    int a, b;
    if(_tree[_i].e[0].first==parent)
    {
      a =_tree[_i].e[1].first;
      b =_tree[_i].e[2].first;
    }
    else if(_tree[_i].e[1].first==parent)
    {
      a =_tree[_i].e[0].first;
      b =_tree[_i].e[2].first;
    }
    else
    {
      a =_tree[_i].e[0].first;
      b =_tree[_i].e[1].first;
    }

    for(int i = 0; i<=100; i++)
    for(int j = 0; j<=100; j++)
      {
          _tree[_i].dp[i+j] = min(_tree[_i].dp[i+j],_tree[a].dp[i]+_tree[b].dp[j]);
      }
  }


  _tree[_i].dp[_tree[_i].size] = _tree[_i].dp[_tree[_i].size-1] + prevSize;

  return _tree[_i].size;

}

int main()
{
  ios::sync_with_stdio(false);
  int n, k;
  int tmp1, tmp2, tmp3;
  int summ = 0;

  cin >> n >> k;

  for(int i = 1; i<n; i++)
  {
    cin >> tmp1 >> tmp2 >> tmp3;
    _tree[tmp1-1].e.push_back(make_pair(tmp2-1,tmp3));
    _tree[tmp2-1].e.push_back(make_pair(tmp1-1,tmp3));
    summ+=tmp3;
  }
  _tree[0].e.push_back(make_pair(1500,0));
  DFS(0,1500,0);

  cout << summ- _tree[0].dp[n-k-1] ;

  return 0;
}

