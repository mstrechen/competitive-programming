#include<iostream>

using namespace std;

int a[200];
int b[200];
int main()
{
  ios::sync_with_stdio(false);
  int n, m;
  char c;
  cin >> n >> m;
  for(int i = 0; i<m; i++)
  {
    for(int j = 0; j<n; j++)
    {
      cin >> c;
      a[i]|=(c=='0');
    }
  }
  int maxSeq = 0;
  int currSeq = 0;
  for(int i = 0; i<=m; i++)
  {
    if(a[i])
      currSeq++;
    else
    {
      maxSeq = max(maxSeq, currSeq);
      currSeq = 0;
    }
  }
  cout << maxSeq;
  return 0;
}
