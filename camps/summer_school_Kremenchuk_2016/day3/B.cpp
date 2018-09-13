#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

const int MAXN = 100500;

set<int> current;
set<int>::iterator it;
struct date
{
  int DD, MM, YYYY,id;
  bool isBegin;
  date(int DD = 0, int MM = 0, int YYYY = 0, int id = 0, bool isBegin = 0):
      DD(DD),
      MM(MM),
      YYYY(YYYY),
      id(id),
      isBegin(isBegin)
  {
  }
  bool operator >(date a)
  {
    if(this->YYYY>a.YYYY)
      return 1;
    else
    if(this->YYYY<a.YYYY)
      return 0;
    else
      if(this->MM>a.MM)
        return 1;
      else
      if(this->MM<a.MM)
        return 0;
      else
        if(this->DD>a.DD)
          return 1;
        else
        if(this->DD<a.DD)
          return 0;
        else return this->isBegin>a.isBegin;

  }
  bool operator <(date a)
  {
      if(this->YYYY>a.YYYY)
      return 0;
    else
    if(this->YYYY<a.YYYY)
      return 1;
    else
      if(this->MM>a.MM)
        return 0;
      else
      if(this->MM<a.MM)
        return 1;
      else
        if(this->DD>a.DD)
          return 0;
        else
        if(this->DD<a.DD)
          return 1;
        else return this->isBegin<a.isBegin;
  }
};
vector<date> A;
bool comp(date a, date b)
{
  return a<b;
}
int main()
{
  ios::sync_with_stdio(false);
  int n;
  int tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;
  cin >> n;
  for(int i = 0; i<n; i++)
  {
    cin >> tmp1 >> tmp2 >> tmp3 >> tmp4 >> tmp5 >> tmp6;
    date be(tmp1,tmp2, tmp3+18,i,1), en(tmp1,tmp2, tmp3+80,i,0), death(tmp4,tmp5,tmp6,i,0);
    if(en>death)
      en = death;
    if(en>be)
    {
      A.push_back(be);
      A.push_back(en);
    }
  }

  A.push_back(date(10000,10000, 10000,100500,0));
  sort(A.begin(), A.end(), comp);

  bool flag = 0;
  int countOfOutputs = 0;
  for(int i = 0; i<A.size(); i++)
  {
    if(flag&&A[i].isBegin==0)
    {
        flag = 0;
        for(it = current.begin(); it!=current.end(); ++it)
        {
          cout << *it +1<< ' ';
        }
        cout << '\n';
        current.erase(A[i].id);
        countOfOutputs++;
    }
    else if(A[i].isBegin)
    {
      current.insert(A[i].id);
      flag = 1;
    }
    else
    {
      current.erase(A[i].id);
    }

  }
  if(countOfOutputs==0)
    cout << 0;

  return 0;
}
