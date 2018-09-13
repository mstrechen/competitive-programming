#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<hash_map>
#include<vector>

using namespace __gnu_cxx;
using namespace std;

const int INF = 1000000;
const int dINF = 2*INF;

const int MEMSZ = 1e8;
char MEM[MEMSZ];
int SZ = 0;
char* res;
inline void* operator new(const size_t sz)
{

  return MEM + (SZ+=sz)-sz;

}

inline void operator delete(void*) {}

struct _vector
{
  int a[8];
  int _sz;
  inline bool operator()(const _vector &b, const _vector &a)
  {
    for(int i = 0; i<7; i++)
      if(a.a[i]!=b.a[i])
        return a.a[i]>b.a[i];
    return a.a[7]>b.a[7];
  }
  inline _vector(int a = 0, int b = 0)
  {
    _sz = a;
    for(int i = 0; i<a; i++)
      this->a[i] = b;
  }
  inline bool operator < (const _vector &a) const
  {
    for(int i = 0; i<_sz-1; i++)
      if(a.a[i]!=this->a[i])
        return a.a[i]>this->a[i];
    return a.a[_sz-1]>this->a[_sz-1];
  }
  inline int & operator [](int i)
  {
    return this->a[i];
  }
};

hash_map<_vector, int, _vector> M;

int be = 2, en = 3;

inline void makeMask(_vector &a,  int mask, int cnt, int currPos)
{
  int currMin = a[__builtin_ffs(mask)-1];
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

char s[100500];
int main()
{
  int countOfDiffChars = 0, countOfDifferentMasks;


  scanf("%s",&s);
  int n = strlen(s);
  for(int i = 0; i<n; i++)
    countOfDiffChars = max(countOfDiffChars, s[i]-'a');
  countOfDiffChars++;
  countOfDifferentMasks = 1<<countOfDiffChars;

  _vector tmp(countOfDiffChars, 0);

  for(int j = 1; j<countOfDifferentMasks; j++)
  {
    makeMask(tmp,j,countOfDiffChars,1);
  }


  for(int i = 0; i<n; i++)
  {
    tmp[s[i]-'a']++;
    for(int j = 1; j<countOfDifferentMasks; j++)
    {
      makeMask(tmp,j,countOfDiffChars,i+2);
    }
  }
  cout << be-2 << ' ' << en-2;
  return 0;
}
