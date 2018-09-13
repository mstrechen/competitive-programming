#include<iostream>
#include<vector>

using namespace std;


const int MAXN = 100500;

struct segment_tree
{
  int wasChangedTo[4*MAXN];
  int sizeOfTree;
  void makeTree(int n)
  {
    while(n&(n+1))
    {
      n|=n+1;
    }
    n++;
    this->sizeOfTree = n;
  }

} st;

vector<int> e[MAXN];
vector<int> seqOfDFS;
int costOfScums[MAXN];

int in[MAXN];
int out[MAXN];

int O_SHIT_WADUP_COUNTER = 0;

void DFS(int _i)
{
  in[_i] = O_SHIT_WADUP_COUNTER++;
  seqOfDFS.push_back(_i);
  for(int i = 0; i<e[_i].size(); i++)
  {
    DFS(e[_i][i]);
  }
  out[_i] = O_SHIT_WADUP_COUNTER++;
  seqOfDFS.push_back(_i);
}
int DFS_summ(int _i)
{
  int ans = costOfScums[_i];
  for(int i = 0; i<e[_i].size(); i++)
    ans+=DFS_summ(e[_i][i]);
  return ans;
}
int DFS_min(int _i)
{
  int ans = costOfScums[_i];
  for(int i = 0; i<e[_i].size(); i++)
    ans=min(ans,DFS_min(e[_i][i]));

  return ans;

}
void DFS_add(int _i, int val)
{
  costOfScums[_i]+=val;
  for(int i = 0; i<e[_i].size(); i++)
    DFS_add(e[_i][i], val);
}
void DFS_set(int _i, int val)
{
  costOfScums[_i]=val;
  for(int i = 0; i<e[_i].size(); i++)
    DFS_set(e[_i][i], val);
}

int main()
{
  ios::sync_with_stdio(false);

  int n,m;
  cin >> n;
  seqOfDFS.reserve(n*2);
  int tmp,tmp1,tmp2,tmp3;
  for(int i = 0; i<n; i++)
  {
    cin >> costOfScums[i];
    cin >> tmp;
    e[i].reserve(tmp);
    for(int j = 0; j<tmp; j++)
    {
      cin >> tmp1;
      e[i].push_back(tmp1-1);
    }
  }
  cin >> m;
  DFS(0);
  for(int i = 0; i<m; i++)
  {
    cin >> tmp;
    if(tmp==1)
    {
      cin >> tmp1 >> tmp2 >> tmp3;
      if(costOfScums[tmp1-1]<tmp2)
        costOfScums[tmp1-1]+=tmp3;
    }
    else
    if(tmp==2)
    {
      cin >> tmp1 >> tmp2 >> tmp3;
      tmp = DFS_summ(tmp1-1)/((out[tmp1-1]-in[tmp1-1]+1)>>1);

      if(tmp<tmp2)
        DFS_add(tmp1-1,tmp3);
    }
    else
    {
      cin >> tmp1;
      tmp = DFS_min(tmp1-1);

      DFS_set(tmp1-1, tmp);
    }
  }

  for(int i = 0; i<n; i++)
    cout << costOfScums[i] << '\n';



  return 0;
}
