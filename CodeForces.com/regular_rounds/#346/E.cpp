#include<iostream>
#include<vector>

using namespace std;

vector<int> a[100000];

int used[100000];

bool dfs(int v, int i)
{
  bool ans = false;
  used[v] = i;
  for(int j = 0; j<a[v].size(); j++)
  {
    if(used[a[v][j]]==0)
    {
      ans|=dfs(a[v][j],i+1);
    }
    else
    if(used[a[v][j]]!=i-1)
    {
      ans = true;
    }
  }
  return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  int n,m,tmp1,tmp2,answer = 0;
  cin >> n >> m;
  for(int i = 0; i<m; i++)
  {
    cin >> tmp1 >> tmp2;
    tmp1--;
    tmp2--;
    a[tmp1].push_back(tmp2);
    a[tmp2].push_back(tmp1);
  }
  for(int i = 0; i<n; i++)
  {
    if(used[i]==0)
    {
      answer+=1-dfs(i,1);
    }
  }
  cout << answer;
  return 0;
}

