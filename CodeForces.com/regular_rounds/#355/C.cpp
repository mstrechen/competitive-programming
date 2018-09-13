#include<iostream>
#include<string>

using namespace std;


const long long mod = 1000000007;


int numOfWord(char c)
{
  if(c=='-')
    return 62;
  if(c=='_')
    return 63;
  if(c<='9')
    return c-'0';
  if(c<='Z')
    return c-'A'+10;
  if(c<='z')
    return c-'a'+36;
}

int numOfVariants(char c)
{
  int tmp = numOfWord(c);
  int variants=1;
  for(int i = 0; i<6; i++)
    variants*=((tmp>>i)&1)?1:3;
  return variants;
}

string s;

int main()
{
  ios::sync_with_stdio(false);
  cin >> s;
  long long variants = 1;
  for(int i = 0; i<s.length(); i++)
  {
    variants*=numOfVariants(s[i]);
    variants%=mod;
  }
  cout << variants%mod;

  return 0;
}
