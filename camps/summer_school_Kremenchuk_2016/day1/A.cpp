#include<iostream>
#include<vector>

using namespace std;

const int MAXN= 100500;

vector<int> edges[MAXN];
int counts[MAXN];

bool visited[MAXN];

vector<int> st;
bool DFS_CHECK(int _i)
{
  st.push_back(_i);
  if(visited[_i])
  {
    int countOf2 = edges[_i].size();
    for(int i = st.size()-2; st[i]!=_i; i--)
    {
      countOf2+=(edges[st[i]].size()==2);
    }
    if(countOf2<2)
      return 1;
    else
      return 0;
  }
  visited[_i] = 1;
  bool answer = 0;
  for(int i = 0; i<edges[_i].size(); i++)
  {
    answer|=DFS_CHECK(edges[_i][i]);
  }
  return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  int n,m;
  int powWith1 = 0;
  int powWith2 = 0;
  int tmp1,tmp2;
  cin >> n >> m;
  for(int i = 0; i<m; i++)
  {
    cin >> tmp1 >> tmp2;
    tmp1--;
    tmp2--;

    edges[tmp1].push_back(tmp2);
    edges[tmp2].push_back(tmp1);

    powWith1+=(edges[tmp1].size()==1)+(edges[tmp2].size()==1)
    -(edges[tmp1].size()==2)+(edges[tmp2].size()==2);
  }
  for(int i = 0; i<n; i++)
  {
    counts[edges[i].size()]++;
  }
  for(int i = 3; i<=n; i++)
  {
    if(counts[i]&1)
    {
      cout << "NO";
      return 0;
    }
  }
  bool flag = 1;
  for(int i = 0; flag&&i<n;i++)
  {
    if(edges[i].size()==2)
    {
      if(DFS_CHECK(i))
      {
        cout << "NO";
      }
      flag = 0;
    }
  }
  if(powWith1==1||powWith1>2||(m&1)||counts[0]>0||powWith2<m-n+2)
    cout << "NO";
  else
    cout << "YES";

  return 0;
}
