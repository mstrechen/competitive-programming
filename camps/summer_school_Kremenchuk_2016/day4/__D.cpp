#include<iostream>
#include<cstdio>
#include<string>
#include<hash_map>
#include<vector>

using namespace __gnu_cxx;

using namespace std;


const int INF = 1000000;
const int dINF = 2*INF;


namespace __gnu_cxx{
  template<>
  struct hash<vector<int> >
  {
    size_t operator()(const vector<int> & a) const
    {
      size_t _h = 0;
      for(int i = 0; i<a.size(); i++)
      {
        _h*=13371488;
        _h+=a[i];
      }
      return _h;
    }
  };
}

hash_map<vector<int>, int> M;


int be = 2, en = 3;

void makeMask(vector<int> &a,  int mask, int cnt, int currPos)
{
  int currMin = a[__builtin_ffs(mask)-1];
  if(!(mask&(mask-1)))
  {
    return;
  }
  for(int i = 0; i<cnt; i++)
  {
    if((mask>>i)&1)
    {
      a[i]-=currMin;
    }
    else
    {
      a[i]-=dINF;
    }
  }
  int currBe;

  if(currBe = M[a])
  {
    currBe++;
    if(en+currBe<currPos+be)
    {
      be = currBe;
      en = currPos;
    }
  }
  else
  {
    M[a] = currPos;
  }
  for(int i = 0; i<cnt; i++)
  {
    if((mask>>i)&1)
    {
      a[i]+=currMin;
    }
    else
    {
      a[i]+=dINF;
    }
  }

}

int main()
{
  ios::sync_with_stdio(false);
  string s;
  int countOfDiffChars = 0, countOfDifferentMasks;

  getline(cin, s);

  for(int i = 0; i<s.size(); i++)
    countOfDiffChars = max(countOfDiffChars, s[i]-'a');
  countOfDiffChars++;
  countOfDifferentMasks = 1<<countOfDiffChars;

  vector<int> tmp(countOfDiffChars, 0);

  for(int j = 1; j<countOfDifferentMasks; j++)
  {
    makeMask(tmp,j,countOfDiffChars,1);
  }

  for(int i = 0; i<s.size(); i++)
  {
    tmp[s[i]-'a']++;
    for(int j = 1; j<countOfDifferentMasks; j++)
    {
      makeMask(tmp,j,countOfDiffChars,i+2);
    }
  }
  char prev = s[0];
  int currBe = 2, currEn = 2;
  for(int i = 1; i<=s.size(); i++)
  {
    if(prev==s[0])
      currEn++;
    else
    {
      if(currEn-currBe>be-en)
      {
        be = currBe;
        en = currEn;
      }
      currBe = currEn+1;
      currEn = currBe;
    }
  }
  cout << be-2 << ' ' << en-2;
  return 0;
}

