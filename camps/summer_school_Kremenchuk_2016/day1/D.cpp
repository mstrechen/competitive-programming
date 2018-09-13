#include<iostream>
#include<set>
#include<vector>

using namespace std;


set<pair<long long,int> > a;
set<pair<long long,int> >::iterator it;

const long long MININF = -1e15;
vector<int> friends;
pair<int,int> tmp;
int minCost[100500];
int main()
{
  int n;
  long long VAL, maxValue;
  int tmp1, tmp2;
  cin >> n >> VAL;
  for(int i = 0; i<n; i++)
  {
    cin >> tmp1 >> tmp2;
    a.insert(make_pair(tmp1,i));
    minCost[i] = tmp2;
  }
  bool flag = 1;
  while(flag)
  {
    flag = 0;
    it = a.begin();
    maxValue = -1;
    while(it!=a.end()&&(*it).first<=VAL)
    {
      if(maxValue<minCost[(*it).second])
      {
        maxValue = minCost[(*it).second];
        tmp = *it;
      }
      flag  = 1;
      it++;
    }
    if(maxValue>-1)
    {
      a.erase(tmp);
      friends.push_back(tmp.second);
      VAL+=maxValue;
    }
    else
    {
      flag = 0;
    }
  }
  flag = 1;
  while(flag)
  {
    flag = 0;
    it = a.begin();
    maxValue = 100500;
    while(it!=a.end()&&(*it).first<=VAL)
    {
      if(maxValue>distance(a.lower_bound(make_pair(VAL,0)), a.upper_bound(make_pair(VAL-minCost[(*it).second],0)))-((*it).second<VAL-minCost[(*it).second],0))
      {
        maxValue = distance(a.lower_bound(make_pair(VAL,0)), a.upper_bound(make_pair(VAL-minCost[(*it).second],0)))-((*it).second<VAL-minCost[(*it).second],0);
        tmp = *it;
      }
      flag  = 1;
      it++;
    }
    if(flag)
    {
      a.erase(tmp);
      friends.push_back(tmp.second);
      VAL+=minCost[tmp.second];
    }
  }

  cout << friends.size() << '\n';
  for(int i = 0; i<friends.size(); i++)
  {
    cout << friends[i]+1 << ' ';
  }

  return 0;
}
