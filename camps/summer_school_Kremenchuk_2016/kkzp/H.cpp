#include<iostream>
#include<cstdlib>


using namespace std;

long long sqr(long long a)
{
  return a*a;
}


long long binPow(long long a, long long p, long long mod)
{
  if(p==0)
    return 1;
  if(p&1)
    return (binPow(a,p-1,mod)*a)%mod;
  return sqr(binPow(a,p/2,mod))%mod;
}

int main()
{
  ios::sync_with_stdio(false);

  long long g, p, A,B,a = 1, tmp;
  cin >> g >> p >> A >> B;
  tmp = g;
  while(tmp!=A&&tmp!=B)
  {
    tmp*=g;
    tmp%=p;
    a++
  }

  if(tmp==A)
    cout << binPow(B,a,p);
  else
    cout << binPow(A,a,p);
  return 0;
}
