#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int a[300][300];

vector < pair<pair<int,int>, int> > allX[90002];
int main()
{
  fstream cin("input.txt");
  ios::sync_with_stdio(false);
  int n,m,p;
  cin >> n >> m >> p;
  for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++)
    {
        cin >> a[i][j];
        allX[a[i][j]].push_back({{i,j},100500000});
    }
  for(int i = 0; i<allX[1].size(); i++)
    allX[1][i].second = allX[1][i].first.first+allX[1][i].first.second;

  for(int _i = 1; _i<p; _i++)
  {
    for(int i = 0; i<allX[_i+1].size(); i++)
      for(int j = 0; j<allX[_i].size(); j++)
        allX[_i+1][i].second = min(allX[_i+1][i].second, allX[_i][j].second+
                                    abs(allX[_i+1][i].first.first -  allX[_i][j].first.first)+
                                    abs(allX[_i+1][i].first.second -  allX[_i][j].first.second));
  }

  cout << allX[p][0].second;

  return 0;
}
