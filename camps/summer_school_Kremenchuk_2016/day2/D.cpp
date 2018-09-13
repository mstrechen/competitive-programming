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

} _tree[MAXN];
bool visited[MAXN];

int DFS(int _i)
{
  visited[_i] = 1;
  int toChoose = -1,tmp;
  for(int i = 0; i<_tree[_i].e.size(); i++)
  {
    if(!visited[_tree[_i].e[i]])
    {
      tmp = DFS(_tree[_i].e[i]);
      if(tmp==-1)
      {
          if(toChoose==-1)
            toChoose = _tree[_i].e[i];
          else
            toChoose = min(_tree[_i].e[i], toChoose);
      }

    }
  }
  return toChoose;
}

int main()
{
  ios::sync_with_stdio(false);
  int n,k;
  long long  tmp1, tmp2;
  cin >> n >> k;
  for(int i = 1; i<n; i++)
  {
    cin >> tmp1 >> tmp2;
    --tmp1;
    --tmp2;
    _tree[tmp1].e.push_back(tmp2);
    _tree[tmp2].e.push_back(tmp1);
  }
  tmp1 = DFS(k-1);
  if(tmp1==-1)
  {
    cout << "First player loses";
  }
  else
  {
    cout << "First player wins flying to airport " << tmp1+1;
  }
  return 0;
}
