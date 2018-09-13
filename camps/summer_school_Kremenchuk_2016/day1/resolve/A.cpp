#include<iostream>
#include<set>

const int MAXN = 100500;

using namespace std;

int n,m;

int visited[MAXN];
int deleted[MAXN];

int DFS(int v)
{
  visited[v] = 1;
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int tmp1,tmp2;
  for(int i = 0; i<m; i++)
  {
    cin >> tmp1 >> tmp2;
    tmp1--;
    tmp2--;
    edges[tmp1].push_back(tmp2);
    edges[tmp2].push_back(tmp1);
  }
  for(int i = 0; i<n; i++)
    DFS(i);
  for(int i = 0; i<n; i++)
  {

  }

  return 0;
}
