#include<iostream>
#include<vector>
#include<set>
#include<functional>

using namespace std;

const int MAXN = 1e5+500;
const long long INF = 1000000000000000L;


long long _max(long long a, long long b)
{
  return a>b?a:b;
}
long long _min(long long a, long long b)
{
  return a<b?a:b;
}


struct edge
{
  long long t, l;
  int to;
  edge(long long l, long long t, int to):t(t), l(l), to(to)
  {}
  long long getTime(long long S)
  {
    return _min(S-this->l, this->t-this->l);
  }
};

struct node
{
  vector<edge> e;
  long long s;
  node(long long s = -1):s(s)
  {}

} _tree[MAXN];
bool visited[MAXN];

set<pair<long long ,int>,greater<pair<long long ,int> > > q;

int main()
{
  ios::sync_with_stdio(false);
  int n;
  long long  tmp1, tmp2, tmp3,tmp4;
  cin >> n;
  for(int i = 1; i<n; i++)
  {
    cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
    --tmp1;
    --tmp2;
    _tree[tmp1].e.push_back(edge(tmp3,tmp4,tmp2));
    _tree[tmp2].e.push_back(edge(tmp3,tmp4,tmp1));
  }
  for(int i = 0; i<n; i++)
  {
    if(_tree[i].e.size()==1)
    {
      q.insert(make_pair(INF,i));
      _tree[i].s = INF;
    }
  }
  int answer = n==1;
  while(!q.empty())
  {
    long long S = q.begin()->first;
    int current = q.begin()->second;
    q.erase(make_pair(S,current));
    if(S<0)
      continue;
    if(visited[current]==0)
    {
      visited[current]=1;
      answer++;
    }
    for(int i = 0; i<_tree[current].e.size(); i++)
    {
      if(_tree[_tree[current].e[i].to].s<_tree[current].e[i].getTime(S))
      {
        _tree[_tree[current].e[i].to].s = _tree[current].e[i].getTime(S);
        q.insert(make_pair(_tree[_tree[current].e[i].to].s,_tree[current].e[i].to));
      }
    }

  }
  cout << answer;
  return 0;
}

