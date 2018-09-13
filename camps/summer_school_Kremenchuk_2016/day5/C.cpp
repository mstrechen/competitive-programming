#include<iostream>
#include<fstream>


using namespace std;

int field[150][150];

int dividers[25];

bool visited[150][150];

int minRes = 2000000000;

int check(int x, int y, int n, int m, int lca)
{
  if(x<0||x>=n||y<0||y>=m)
    return 0;
  return (visited[x][y]==0)&&(lca%field[x][y]==0);
}

bool DFS(int lca, int x, int y, int n, int m)
{
  if(x==n-1&&y==m-1)
  {
    return 1;
  }
  bool ans = 0;
  visited[x][y] = 1;
  if(check(x+1,y,n,m,lca))
    ans|=DFS(lca,x+1,y,n,m);
  if(check(x-1,y,n,m,lca))
    ans|=DFS(lca,x-1,y,n,m);
  if(check(x,y+1,n,m,lca))
    ans|=DFS(lca,x,y+1,n,m);
  if(check(x,y-1,n,m,lca))
    ans|=DFS(lca,x,y-1,n,m);
  return ans;
}

void rec(int _i, int LCA, int n, int m)
{
  if(_i==25)
  {
    for(int i = 0; i<150; i++)for(int j = 0; j<150; j++)visited[i][j] = 0;

    if((LCA%field[0][0]==0)&&DFS(LCA,0,0, n, m))
    {
      minRes = min(minRes, LCA);
    }
  }
  else
  {
    for(int i = 0; i<=dividers[_i]; i++)
    {
      rec(_i+1, LCA, n, m);
      LCA*=_i;
    }
  }
}
int main()
{
  //ifstream cin("magiclab.in");
  //ofstream cout("magiclab.out");
  int n, m;
  cin >> n >> m;
  for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++)
    {
      cin >> field[i][j];
      int tmp = field[i][j];
      int tmp2;
      for(int k = 2; k*k<=tmp; k++)
      {
        tmp2 = 0;
        while(tmp%k==0)
        {
          tmp/=k;
          tmp2++;
        }
        dividers[k] = max(dividers[j], tmp2);
      }
      if(tmp>1)
      {
        dividers[tmp] = max(dividers[tmp], 1);
      }
    }
  rec(2,1,n,m);
  cout << minRes;

  return 0;
}
