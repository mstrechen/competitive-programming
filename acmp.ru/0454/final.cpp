#include<iostream>
using namespace std;

int main()
{
  long long a,b, l = 1, s = 1;
  cin >> a >> b;
  b = b-a+1;

  while(s<b)
  {
    l*=4;
    s+=l;
  }

  cout << s-l+ a;

  return 0;
}
