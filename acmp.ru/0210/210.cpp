#include <iostream>
#include <iostream>

using namespace std;


long long factorized[20][2];
long long countOfDividers = 0;
long long answer;
long long n;

long long powWithMod(long long a, long long _n, long long modular)
{
  if(_n==1)
    return a;
  if(_n&1)
    return (a*powWithMod(a,_n-1,modular))%modular;

  long long tmp = powWithMod(a,_n>>1, modular);
  return (tmp*tmp)%modular;
}

void findAllVariants(long long i = 0, long long a = 1)
{
  if(i==countOfDividers)
  {
    if(powWithMod(a,a,n)==0)
      answer = min(answer,a);
  }
  else
  {
    for(long long j = 1; j<=factorized[i][1]; j++)
    {
      a*=factorized[i][0];
      findAllVariants(i+1, a);
    }
  }
}

int main()
{

  cin >> n;
  long long nTmp = n;
  answer = n;

  for(long long i = 2; i*i<=nTmp; i++)
  {
    if(nTmp%i==0)
    {
      factorized[countOfDividers][0] = i;
      while(nTmp%i==0)
      {
        factorized[countOfDividers][1]++;
        nTmp/=i;
      }
      countOfDividers++;
    }

  }

  if(nTmp!=1)
  {
    factorized[countOfDividers][0] = nTmp;
    factorized[countOfDividers++][1] = 1;

  }

  findAllVariants();
  cout << answer;


  return 0;
}
