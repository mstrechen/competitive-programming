#include<iostream>
#include<string>

using namespace std;

string s;

int main()
{
  int l=0, r;
  long long currL = 0, currR = 0;
  int n;
  cin >> n;
  cin >> s;
  for(int i = 1; i<s.size(); i++)
    l+=s[i]==s[i-1];
  r = l+2;
  bool turnright = s[0]=='L';
  cout << s[0] << ' ' << r-1 << '\n';
  if(s[0]=='L')
    currL = r-1;
  else
    currR = r-1;

  for(int i = 1; i<n; i++)
  {
    if(s[i]!=s[i-1])
    {
      if(currR>currL)
      {
        currL+=r;
        cout << "L " <<r++;
      }
      else
      {
          currR+=r;
           cout << "R " <<r++;
      }
    }
    else
    {

      if(turnright)
      {
        currR+=l;
        cout << "R " << l--;
      }
      else
      {
        currL+=l;
        cout << "L " << l--;
      }
      turnright^=1;
    }
    cout << '\n';
  }
  return 0;
}

