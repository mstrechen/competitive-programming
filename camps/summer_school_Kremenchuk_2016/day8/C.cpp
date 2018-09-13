#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

long long prefixSumm[100500];
long long a[100500];

long long min(long long a, long long b)
{
  return a>b?b:a;
}
long long max(long long a, long long b)
{
  return a>b?a:b;
}


struct _segmentTree
{
  long long summs[1048577];
  long long _size;
  _segmentTree(int a)
  {
    _size = 524288;
    for(int i = 0; i<=_size*2; i++)
      summs[i]=0;
  }
  void update(int i)
  {
    _update(1,i,i,1,1, _size);
  }
  void _update(int a, int l, int r, int currI, int minL, int maxR)
  {
    if(l>r)
      return;
    summs[currI]+=a*(l-r+1);
    int mid = (minL+maxR)/2;
    if(currI<_size)
    {
      _update(a, l, min(r,mid), currI*2, minL, mid);
      _update(a, max(l,mid+1), r, currI*2+1, mid, maxR);
    }
  }
  long long getCount(int l, int r)
  {
      return _getCount(l, r, 1, 1, _size);
  }
  long long _getCount(int l, int r, int currI, int minL, int maxR)
  {
    if(l>r)
    {
          return 0;
    }
    int mid = (minL+maxR)/2;
    if(l==minL&&r==maxR)
    {
      return summs[currI];
    }
    return _getCount(l, min(r,mid), currI*2, minL, mid)+_getCount(max(l, mid+1),r, currI*2+1, mid+1, maxR);
  }

} st(0);


map<long long, int> compressed;

int main()
{
  ios::sync_with_stdio(false);

  int n;
  long long k;
  cin >> n >> k;
  prefixSumm[0] = 0;//-k
  for(int i = 1; i<=n; i++)
  {
    cin >> a[i];
    prefixSumm[i]=a[i]+prefixSumm[i-1]-k;
  }

  vector<long long> possibleVars;
  possibleVars.assign(prefixSumm, prefixSumm+1+n);
  sort(possibleVars.begin(),possibleVars.end());
  int counter = 1;

  for(int i = 0; i<possibleVars.size(); i++)
  {
    if(!compressed.count(possibleVars[i]))
    {
      compressed[possibleVars[i]] = counter++;
    }
  }
  long long ans = a[1]<=k;

  st.update(compressed[prefixSumm[0]]);

  for(int i = 2; i<=n; i++)
  {
      ans+=a[i]<=k;
      ans+=st.getCount(compressed[prefixSumm[i]], 100500);
      st.update(compressed[prefixSumm[i-1]]);
  }

  cout << ans;

  return 0;
}
