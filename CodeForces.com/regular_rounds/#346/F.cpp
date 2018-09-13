#include<iostream>
#include<set>

using namespace std;

int a[1000][1000], b[1000][1000];
pair<int,int> q[1000000];
int en = 0;
int main()
{

  freopen("inp.txt", "r", stdin);
  ios::sync_with_stdio(false);
  long long k, summ = 0,n,m,nm;;


  cin >> n >> m >> k;
  nm = n*m;
  for(int i = 0; i<n; i++)
  {
    for(int j = 0; j<m; j++)
    {
      cin >> a[i][j];
      summ+=a[i][j];
    }
  }
  if(summ<k)
  {
    cout << "NO";
  }
  else
  {
    for(int i = 0; i<n; i++)
    {
      for(int j = 0; j<m; j++)
      {
        if(k%a[i][j]==0)
        {
          if(nm*a[i][j]>=k)
          {
            nm = k/a[i][j];
            int tmp = a[i][j];
            q[0] = make_pair(i,j);
            en = 1;

            for(int o = 0; o<nm; o++)
            {
              b[i][j] = tmp;
              int x = q[o].first, y = q[o].second;
              b[x][y] = tmp;
              if(x>0)
              {
                q[en++] = make_pair(x-1,y);
              }
              if(x<n-1)
              {
                q[en++] = make_pair(x+1,y);
              }
              if(y>0)
              {
                q[en++] = make_pair(x,y-1);
              }
              if(y<m-1)
              {
                q[en++] = make_pair(x,y+1);
              }
            }
            cout << "YES\n";
            for(int i1 = 0; i1<n; i1++)
            {
              for(int j1 = 0; j1<m; j1++)
              {
                cout << b[i1][j1] << ' ';
              }
              cout << '\n';
            }
            return 0;
          }
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
