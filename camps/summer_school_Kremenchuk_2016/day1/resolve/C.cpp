#include<iostream>
#include<algorithm>


using namespace std;

const int MAXN = 100002;

pair<long long, long long> p[MAXN];
long long last[MAXN];

int solve(int n)
{
  int k = 0;
  for(int i = 0; i<n; i++)
  {
    int l = k+1, r=0,mid;
    while(l>r+1)
    {
      mid  = (l+r)/2;
      if(last[mid]<=p[i].second)
        r = mid;
      else
        l = mid;
    }
    last[l] = p[i].second;
    k+=(l==k+1);
  }
  return k;
}

int main()
{
  int n;
  long long x,t;
  long long v;

  cin >> n;
  for(int i = 0; i<n; i++)
  {
    cin >> p[i].first >> p[i].second;
  }
  cin >> v;
  for(int i = 0; i<n; i++)
  {
    x = p[i].first;
    t = p[i].second;
    p[i].first = -x + v*t;
    p[i].second = x + v*t;
  }
  sort(p,p+n);
  int res;
  res = solve(n);
  for(int i = 0; i<n;)
   {
     if(p[i].first<0||p[i].second<0)
     {
       swap(p[i], p[n-1]);
       n--;
     }
     else
      i++;
   }
   sort(p,p+n);
   cout << solve(n) <<  ' '<< res;
  return 0;
}
