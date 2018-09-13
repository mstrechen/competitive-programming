#include<iostream>
#include<fstream>

using namespace std;

long long getCountOfPowPair(long long summ)
{
  long long ans = 0;
  for(long long i = 1; i*i<summ; i++)
    ans+=summ-i*i;
  return ans;
}

int solve(long long n)
{
  long long ans = 0;
  for(long long i = 1; i*i*i<n; i++)
  {
    ans+=getCountOfPowPair(n-i*i*i);
  }
  return ans;
}
int main()
{
  ofstream cout("D_outputA.txt");
  for(int i = 3; i<1000; i++)
    cout << i << ' ' << solve(i) << endl;

  return 0;
}
