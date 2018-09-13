#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 3e5+500;


long long _max(long long a, long long b)
{
  return a>b?a:b;
}
struct node
{
  vector<int> e;
  vector<int> eNum;
  long long t1,t2,s1,s2;
  long long size;
  node():t1(0),t2(0),s1(0),s2(0),size(0)
  {
  }
} _tree[MAXN];
bool visited[MAXN];
bool visited1[MAXN];
long long values[MAXN];

long long DFS(int _i, int n)
{
  if(visited[_i])
    return 0;
  visited[_i] = 1;
  _tree[_i].s1 = 1;
  for(int i = 0; i<_tree[_i].e.size(); i++)
  {
    if(visited[_tree[_i].e[i]])
      continue;
    long long tmp = DFS(_tree[_i].e[i],n);
    _tree[_i].s1 += tmp;
    _tree[_i].s2 += _tree[_tree[_i].e[i]].s2+tmp;
  }
  _tree[_i].t1 = n - _tree[_i].s1;
  return _tree[_i].s1;

}

void DFS_V2(int _i, int p, int e)
{
  if(visited1[_i])
    return;
  visited1[_i] = 1;

  if(p!=-1)
    _tree[_i].t2 = _tree[_i].t1+_tree[p].t2+_tree[p].s2-(_tree[_i].s2+_tree[_i].s1);
  else
    _tree[_i].t2 = 0;

  for(int i = 0; i<_tree[_i].e.size(); i++)
  {
    if(!visited1[_tree[_i].e[i]])
    {
      DFS_V2(_tree[_i].e[i], _i, _tree[_i].eNum[i]);
    }
  }
  if(e!=-1)
  {
    values[e] =  _tree[_i].t2*_tree[_i].s1+
                 _tree[_i].t1*_tree[_i].s2;
  }
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
    _tree[tmp1].eNum.push_back(i-1);
    _tree[tmp2].e.push_back(tmp1);
    _tree[tmp2].eNum.push_back(i-1);
  }

  DFS(0, n);
  DFS_V2(0, -1,-1);
  for(int i = 0; i<n-1; i++)
    cout << values[i] << '\n';

  return 0;
}
