#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string a[10000];

void toString(int n, int l)
{
  int b[10];
  int i = 0;
  for(;n>0;n/=10)
  {
    b[i++] = n%10;
  }
  for(int j = i-1; j>=0; j--)
    a[l]+=b[j]+'0';
}

struct comp
{
  bool operator()(string &a, string &b)
  {
    int wasChanged = -1;
    for(int i = 0; i<a.size()&&i<b.size()&&wasChanged==-1; i++)
      if(a[i]<b[i])
        wasChanged = 1;
      else
        if(a[i]>b[i])
          wasChanged = 0;
    if(wasChanged==-1)
      return a.size()<b.size();
    else
      return wasChanged;
  }
} comp1;

int main()
{
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for(int i = 0; i<n; i++)
    toString(i+1,i);
  toString(k,n);
  sort(a, a+n,comp1);
  for(int i = 0; i<n; i++)
    if(a[i]==a[n])
    {
      cout << i+1;
      return 0;
    }
  return 0;
}
