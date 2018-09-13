#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>


using namespace std;

map<pair<pair<int,int>,pair<int,int> >,int> handle;
int A[30],B[30];

int getPos(const pair<pair<int,int>, pair<int,int> > & a)
{
  return a.first.first*27000+a.first.second*900+a.second.first*30+a.second.second;
}


int getHandle(pair<pair<int,int>, pair<int,int> > a)
{
  if(a.first.first>a.first.second||a.second.first>a.second.second)
  {
    return  0;
  }
  if(handle[a])
  {
    return handle[a]-1;
  }

  set<int> sset;

  for(int i = a.first.first; i<=a.first.second; i++)
  for(int j = a.second.first; j<=a.second.second; j++)
  {
    if(A[i]==B[j])
      sset.insert(getHandle(make_pair(make_pair(a.first.first,i-1),make_pair(a.second.first, j-1)))^
                 getHandle(make_pair(make_pair(i+1,a.first.second),make_pair(j+1,a.second.second))));

  }
  int j = 0;
  while(sset.count(j))
    j++;
  handle[a] = j+1;
  return j;

}

vector<pair<int,int> >ans;
int main()
{
  ifstream cin("game.in");
  ofstream cout("game.out");
  int n, m;
  cin >> n >> m;
  for(int i = 0; i<n; i++)
    cin >> A[i];
  for(int i = 0; i<m; i++)
    cin >> B[i];
  for(int i = 0; i<n; i++)
    for(int j = 0;j<m; j++)
      if(A[i]==B[j]&&
         !(getHandle(make_pair(make_pair(0,i-1),make_pair(0,j-1)))^
         getHandle(make_pair(make_pair(i+1, n-1),make_pair(j+1, m-1)))))
         {
          ans.push_back(make_pair(i,j));
         };

  if(ans.size()==0)
    cout << "LOSE";
  else
  {
    cout << "WIN\n";
    sort(ans.begin(), ans.end());
    for(int i = 0; i<ans.size(); i++)
      cout << ans[i].first << ' ' << ans[i].second << '\n';

  }

  return 0;
}
