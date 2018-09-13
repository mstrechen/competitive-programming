#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXN = 3000;
const int BAD = -100500;

vector<char> ans;

int field[MAXN][MAXN];
int dist[MAXN][MAXN];


bool check(int x, int y,
           int nSize, int mSize,
           int n, int m,
           int MAGIC)
{
  if(x+nSize-1>n||y+mSize-1>m||y<=0||x<=0)
    return 0;
  if(dist[x][y]!=BAD)
    return 0;
  return field[x+nSize-1][y+mSize-1]+
         field[x-1][y-1]-
         field[x-1][y+mSize-1]-
         field[x+nSize-1][y-1]<=MAGIC;
}
struct queuePoint
{
  int x,y;
  int dist;
  queuePoint(int x = 0, int y = 0, int dist = 0):x(x), y(y), dist(dist)
  {

  }
};
struct _queue
{
  queuePoint a[10000000];
  int l, r;
  _queue(int l = 0, int r = 0) : l(0), r(0){};

  bool empty()
  {
    return l==r;
  }
  void push(queuePoint p)
  {
    this->a[this->r++] = p;
    dist[p.x][p.y] = p.dist;
  }

  void pop()
  {
    this->l++;
  }
}q;


void get1(char & c)
{
  c = getchar();
  while(c!='.'&&c!='X')
    c = getchar();
}

int main()
{
  ios::sync_with_stdio(false);
  int n,m;
  int n_santa, m_santa;
  int MAGIC;
  char tmp;

  cin >> n >> m >> n_santa>> m_santa >> MAGIC;

  for(int i = 0; i<MAXN; i++)
    for(int j = 0; j<MAXN; j++)
      dist[i][j] = BAD;

  for(int i = 1; i<=n; i++)
    for(int j = 1; j<=m; j++)
    {
      cin >> tmp;
      field[i][j] = tmp=='X';
    }


  for(int i = 1; i<=n+1; i++)
    for(int j = 1; j<=m+1; j++)
      field[i][j]+= field[i][j-1]+field[i-1][j]-field[i-1][j-1];


  if(check(n-n_santa+1, m-m_santa+1,n_santa, m_santa, n,m, MAGIC))
    q.push(queuePoint(n-n_santa+1,m-m_santa+1,0));

  while(!q.empty())
  {
    int x = q.a[q.l].x;
    int y = q.a[q.l].y;
    int currDistance = q.a[q.l].dist;
    q.pop();

    if(check(x,y+1,n_santa, m_santa, n,m,MAGIC))
      q.push(queuePoint(x,y+1,currDistance+1));

    if(check(x,y-1,n_santa, m_santa, n,m,MAGIC))
      q.push(queuePoint(x,y-1,currDistance+1));

    if(check(x+1,y,n_santa, m_santa, n,m,MAGIC))
      q.push(queuePoint(x+1,y,currDistance+1));

    if(check(x-1,y,n_santa, m_santa, n,m,MAGIC))
      q.push(queuePoint(x-1,y,currDistance+1));
  }
  if(dist[1][1]==BAD)
  {
    cout << "Santa je chudak.";
  }
  else
  {
    int x = 1;
    int y = 1;
    while(dist[x][y]!=0)
    {

      if(dist[x][y+1]==dist[x][y]-1&&1)
      {
        cout <<'V';
        y++;
      }
      else
      if(dist[x+1][y]==dist[x][y]-1&&2)
      {
        cout <<'J';
        x++;
      }
      else if(dist[x][y-1]==dist[x][y]-1&&4)
      {
        cout << 'Z';
        y--;
      }
      else
      if(dist[x-1][y]==dist[x][y]-1&&3)
      {
        cout <<'S';
        x--;
      }

    }


  }
  cout << endl;
  return 0;
}
