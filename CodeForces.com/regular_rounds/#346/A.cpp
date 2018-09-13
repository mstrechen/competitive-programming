#include<iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int a, b, n;
  cin >> n >> a >>b;
  b = (a+b-1)%n;
  if(b<0) b+=n;
  cout << b+1;
  return 0;
}
