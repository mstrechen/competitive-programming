#include<iostream>

using namespace std;

long long prefixSumm[100500];

long long min(long long a, long long b)
{
  return a>b?b:a;
}
long long max(long long a, long long b)
{
  return a>b?a:b;
}
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 1; i<=n; i++)
  {
    cin >> prefixSumm[i];
    prefixSumm[i]+=prefixSumm[i-1];
  }
  long long minPrefixSumm = 0, maxPrefixSumm = prefixSumm[1];
  for(int i = 1; i<=n; i++)
  {
    minPrefixSumm = min(minPrefixSumm,prefixSumm[i-1]);
    maxPrefixSumm = max(maxPrefixSumm, prefixSumm[i]-minPrefixSumm);
  }
  cout << maxPrefixSumm;
  return 0;
}
