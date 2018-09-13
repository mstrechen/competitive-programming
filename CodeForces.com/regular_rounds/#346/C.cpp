#include<iostream>
#include<set>
#include<string>

using namespace std;

set<int> a;
int b[100500];
int main()
{

  //freopen("inp.txt", "r", stdin);
  ios::sync_with_stdio(false);
  int n,m,tmp,summ = 0, k = 0;
  cin >> n >> m;
  for(int i = 0; i<n; i++)
  {
    cin >> tmp;
    a.insert(tmp);
  }
  for(int i = 1;summ+i<=m;i++)
  {
    if(a.count(i) == 0)
    {
      summ+=i;
      b[k] = i;
      k++;
    }
  }
  cout << k << '\n';
  for(int i = 0; i<k; i++) cout << b[i] << ' ';
  return 0;
}
