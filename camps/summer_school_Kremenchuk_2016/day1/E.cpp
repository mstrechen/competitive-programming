#include<iostream>
#include<string>

using namespace std;


bool isOnlyNines(unsigned long long n)
{
  while(n>0)
  {
    if(n%10!=9)
      return 0;
    n/=10;
  }
  return 1;
}

unsigned long long rotateANumber(unsigned long long n, unsigned long long m = 0)
{
  if(n==0)
  {
    return m;
  }
  else
  {
    m = m*10+n%10;
  }
  return rotateANumber(n/10,m);
}

unsigned long long makePal(unsigned long long n, int len)
{
  unsigned long long second_part;
  if(len&1)
  {
      second_part  = rotateANumber(n/10);
  }
  else
  {
      second_part = rotateANumber(n);
  }
  len>>=1;
  for(int i = 0; i<len; i++)
  {
    n*=10;
  }
  return n+second_part;
}

int main()
{
  unsigned long long n,tmp;
  int lengthOfANumber = 0;
  cin >> n;
  if(isOnlyNines(n))
  {
    cout << 1;
    while(n>10)
    {
      n/=10;
      cout << 0;
    }
    cout << 1;
  }
  else
  {
    tmp = n;
    while(tmp>0)
    {
      tmp/=10;
      lengthOfANumber++;
    }

    unsigned long long possible_answer;
    tmp = n;

    for(int i = 0; i<lengthOfANumber/2; i++)
      tmp/=10;
    if(makePal(tmp, lengthOfANumber)>n)
    {
      cout << makePal(tmp, lengthOfANumber);
    }
    else
    {
      cout << makePal(tmp+1, lengthOfANumber);
    }
  }
  return 0;
}
