#include<iostream>

using namespace std;

int main()
{
  int k;
  long long a,b,c;

  cin >> k;

  for(int i = 0; i<k; i++)
  {
    cin >> a >> b >> c;
    if(a&b&c&1||(a==b&&b==1)||(a==c&&c==1)||(c==b&&c==1))
    {
      cout << "NO\n";
    }
    else
    {
      cout << "YES\n";
    }
  }
  return 0;
}
