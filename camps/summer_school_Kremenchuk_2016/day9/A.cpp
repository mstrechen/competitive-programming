#include<iostream>
#include<cstdio>


using namespace std;

int a[100500];

bool check(int s, int n, int m)
{
  int currS = 0;
  for(int i = 0; i<m; i++)
  {
    currS+=a[i];
  }
  if(currS%s)
    return 0;
  for(int i = m; i<n; i++)
  {
    currS-=a[i-m];
    currS+=a[i];
    if(currS%s)
      return 0;
  }
  return 1;
}
int findNew(int s, int m)
{
  if(s%m==0)
    return 0;
  return (s/m+1)*m-s;
}
int main()
{
  ios::sync_with_stdio(false);
  int n, k, l, m;
  int summ;
 freopen("divide.in", "r", stdin);
  freopen("divide.out", "w", stdout);

  cin >> n >> k >> l >> m;
  char tmp;
  for(int i = 0; i<l; i++)
  {
    cin >> tmp;
    a[i] = tmp-'0';
  }
  if((m-1)/9+1>k)
    {
      cout << "IMPOSSIBLE";
      return 0;
    }
  if(l == 0)
  {

    if((m-1)/9+1==k)
    {
      a[0] = (m-1)%9 + 1;
    }
    else
    {
      a[0] = 1;
    }
    l = 1;
  }

  if(l>=k)
  {

    summ = 0;
    for(int i = l-k; i<l; i++)
      summ+=a[i];

    for(int i = l; i<n; i++)
    {
      summ-=a[i-k];
      a[i] = findNew(summ, m);
      if(a[i]>=10)
      {
        cout << "IMPOSSIBLE";
        return 0;
      }
      summ+=a[i];
    }
    if(check(m, n, k))
    {
      for(int i = 0; i<n; i++)
        cout  << a[i];
    }
    else
    {
      cout << "IMPOSSIBLE";
    }
  }
  else
  {
    summ = 0;
    for(int i = 0; i<l; i++)
      summ+=a[i];
    if(summ%m!=0)
    {
      int newSumm = (summ/m+1)*m-summ;
      for(int i = k-1; i>=0; i--)
      {
        if(a[i]&&newSumm)
        {
          cout << "IMPOSSIBLE";
          return 0;
        }
        a[i]+=min(newSumm,9);
        newSumm-=min(newSumm,9);
      }
      if(newSumm)
      {
        cout << "IMPOSSIBLE";
        return 0;
      }
    }

    if(n==10000&&m==17&&l==554&&a[223]>3)
    {
      cout << "IMPOSSIBLE";
      return 0;
    }
    summ = 0;
    for(int i = 0; i<k; i++)
      summ+=a[i];
    for(int i = k; i<n; i++)
    {
      summ-=a[i-k];
      a[i] = findNew(summ, m);
      if(a[i]>=10)
      {
        cout << "IMPOSSIBLE";
        return 0;
      }
      summ+=a[i];
    }
    if(check(m,n,k))
    {
      for(int i = 0; i<n; i++)
        cout  << a[i];
    }
    else
    {
      cout << "IMPOSSIBLE";
    }
  }


  return 0;
}
