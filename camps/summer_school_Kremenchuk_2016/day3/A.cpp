#include<iostream>
#include<vector>
#include<string>
#include<set>


using namespace std;

const int MAXN = 100500;

struct city
{
  vector<int> e;
  int in;
  int currentCountOfBuses;
  int needMore;
  city(int in = 0, int currentCountOfBuses = 0, int needMore = 0):
    in(in),
    currentCountOfBuses(currentCountOfBuses),
    needMore(needMore)
  {}
} A[MAXN];

int getTime(string s)
{
  return ((s[0]-'0')*10+s[1]-'0')*60+((s[3]-'0')*10+s[4]-'0');
}
set<pair<pair<int, bool>, pair<int,int> > > Q;
set<pair<pair<int, bool>, pair<int,int> > >::iterator it;
int main()
{
  ios::sync_with_stdio(false);
  int n,m;
  string s1, s2;
  int be, en;
  int time1, time2;
  cin >> n >> m;
  for(int i = 0; i<m; i++)
  {
      cin >> be >> s1 >> en >> s2;
      be--;
      en--;
      time1 = getTime(s1);
      time2 = getTime(s2);

      A[be].e.push_back(en);
      A[en].in++;
      Q.insert(make_pair(make_pair(time1,0),make_pair(be,i)));
      Q.insert(make_pair(make_pair(time2,1),make_pair(en,i)));
      Q.insert(make_pair(make_pair(time1+1440,0),make_pair(be,i)));
      Q.insert(make_pair(make_pair(time2+1440,1),make_pair(en,i)));
  }
  int answer = 0;
  for(it = Q.begin(); it!=Q.end(); ++it)
  {
     if(it->first.second)
    {
      A[it->second.first].currentCountOfBuses++;
    }
    else
    {
      if(A[it->second.first].currentCountOfBuses>0)
         A[it->second.first].currentCountOfBuses--;
      else
        A[it->second.first].needMore++;
    }
  }
  for(int i  = 0; i<n; i++)
  {
    if(A[i].currentCountOfBuses!=A[i].needMore)
    {
      cout << -1;
      return 0;
    }
    answer+=A[i].currentCountOfBuses;
  }
  cout << answer;
  return 0;
}
