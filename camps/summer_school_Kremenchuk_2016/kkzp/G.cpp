#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

struct mask
{
  unsigned long long a,b,c,d;
  mask()
  {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
  }
  bool getBit(int n)
  {
    if(n<64)
      return (a>>n)&1;
    if(n<128)
      return (b>>(n-64))&1;
    if(n<192)
      return (c>>(n-128))&1;
    return (d>>(n-192)&1);
  }
  void setBit(int n)
  {
     if(n<64)
      a|=1<<(n-0);
     if(n<128)
      b|=1<<(n-64);
     if(n<192)
      c|=1<<(n-128);
     if(n<64)
      d|=1<<(n-192);
  }
};

mask _a[100500], _b[100500];

mask * a = _a;
mask * b = _b;
int sizeA = 0, sizeB = 0;

int days[200][200];
int main()
{
  ios::sync_with_stdio(false);
  int n, m, tmp;
  string s;
  getline(cin, s);
  istringstream sin(s);
  sin >> n >> m;

  for(int i = 0; i<n; i++)
  {
    getline(cin, s);
    istringstream sin(s);
    while(!sin.eof())
    {
      sin >> tmp;
      days[tmp-1][i] = 1;
    }
  }
  a[0] = mask();
  sizeA++;
  for(int _i = 0; _i<m; _i++)
  {
    bool flag1 = 0;
    sizeB = 0;
    for(int i = 0; i<sizeA; i++)
    {
      for(int j = 0; j<n; j++)
      {
        if(days[_i][j]&&(a[i].getBit(j)==0))
        {
          b[sizeB] = a[i];
          b[sizeB++].setBit(j);
          flag1 = 1;
        }
      }
    }

    if(flag1)
    {
      swap(a,b);
      sizeA = sizeB;
    }

  }
  for(int i = 0; i<n; i++)
  {
    bool ans = 1;
    for(int j = 0; j<sizeA; j++)
      ans&=a[j].getBit(i);

    if(ans)
    {
      cout << i+1 << ' ' ;
    }
  }
  return 0;
}
