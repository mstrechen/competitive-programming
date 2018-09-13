#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int MAXN = 10000000;
set<int> freeDocks;

int docks [MAXN];
pair<int, pair<bool,int>> A[MAXN];
int main()
{
  ios::sync_with_stdio(false);
  int k,n;
  int tmp1, tmp2;
  cin >> k >> n;
  for(int i = 0; i<k; i++)
    freeDocks.insert(i);
  for(int i = 0; i<n; i++)
  {
    cin >> tmp1 >> tmp2;
    A[i*2] = make_pair(tmp1, make_pair(0,i));
    A[i*2+1] = make_pair(tmp2, make_pair(1,i)) ;
  }
  n*=2;
  sort(A, A+n);
  for(int i = 0; i<n; i++)
  {
    if(A[i].second.first==0)
    {
      if(freeDocks.empty())
      {
        cout << "0 " << A[i].second.second+1;
        return 0;
      }
      else
      {
        docks[A[i].second.second] = *freeDocks.lower_bound(0);
        freeDocks.erase(docks[A[i].second.second]);
      }
    }
    else
    {
      freeDocks.insert(docks[A[i].second.second]);
    }
  }
  n/=2;
  for(int i = 0; i<n; i++)
  {
    cout << docks[i]+1 << '\n';
  }
  return 0;
}
