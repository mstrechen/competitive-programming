#include<iostream>
#include<string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  cout << s;
  for(int i = s.size()-1; i>=0; i--)
    cout << s[i];

  return 0;
}
