
#include<iostream>

using namespace std;

int main()
{
  unsigned long long A,B;
  cin >> A >> B;
  unsigned long long _summ = A, _xor = B, _and = (A-B)/2;

  if(((_xor^_summ)&1
  {
    cout << -1;
  }
  else
  cout << _and << ' '<<_summ-_and;

  return 0;
}
