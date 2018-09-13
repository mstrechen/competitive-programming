#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;



long long getCountOfPowPair(long long summ)
{
  long long ans = 0;
  for(long long i = 1; i*i<summ; i++)
    ans+=summ-i*i;
  return ans;
}

const long long MOD = 1000000000;

void printNum(long long a)
{
  long long i = MOD/10;
  while(i>0)
  {
    cout << (a/i)%10;
    i/=10;
  }
}
const int HOWLONGNUMSHOULDBE = 2;

struct longNum
{
  long long num[HOWLONGNUMSHOULDBE];
  longNum(long long a = 0)
  {

    for(int i = 2; i<HOWLONGNUMSHOULDBE; i++)
      this->num[i] = 0;
    this->num[0] = a % MOD;
    this->num[1] = a/MOD;
  }
  void operator+=(long long a)
  {
    this->num[0]+=a;
    this->num[1]+=num[0]/MOD;
    this->num[0]%=MOD;

  }
  void operator+=(longNum b)
  {
    this->num[0]+=b.num[0];
    this->num[1]+=b.num[1]+this->num[0]/MOD;
    this->num[0]%=MOD;
  }
  void print()
  {

    bool flag = 0;
    for(int i = HOWLONGNUMSHOULDBE-1; i>=0; i--)
    {
      if(flag)
      {
        printNum(this->num[i]);
      }
      else
        if(this->num[i])
        {
          flag = 1;
          cout << num[i];
        }
    }
    if(!flag)
      cout << 0;

  }
};
void printLLL(__int128 a)
{
  if(a==0)
    return;
  printLLL(a/10);
  cout << (long long)(a%10);
}

__int128  solve(long long n)
{
  __int128  ans = 0;
  __int128 currAns = 0;
  long long j = 1;
  for(long long i = cbrt(n-1); i>0; i--)
  {
    long long summWithoutCb = n-i*i*i;

    while(summWithoutCb>=j*j)
    {
      currAns+=(j-1)*(2*j-1);
      j++;
    }
    ans+=currAns;
    ans+=(j-1)*(summWithoutCb-(j-1)*(j-1));
  }

  return ans;

}

int main()
{
  long long n;
  cin >> n;
  printLLL(solve(n));

  return 0;
}

