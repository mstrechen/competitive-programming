#include<iostream>
#include<map>
#include<string>

using namespace std;

struct cmp
{
  bool operator ()(int a, int b)
  {
    return a>b;
  }
};

multimap<int,string, cmp>  a[10001];
multimap<int,string, cmp>::iterator it,tmp;


int main()
{

  //freopen("inp.txt", "r", stdin);
  ios::sync_with_stdio(false);
  int n,m;
  int tmp2, tmp3;
  string tmp1;
  cin >> n >> m;
  for(int i = 0; i<n; i++)
  {
    cin >> tmp1 >> tmp2 >> tmp3;
    a[tmp2-1].insert(make_pair(tmp3,tmp1));
  }
  for(int i = 0; i<m; i++)
  {
    int k = 0;
    for(it = a[i].begin(); it!=a[i].end()&&it->first==a[i].begin()->first; it++)
    {
      k++;
    }
    if(k==1)
    {
      tmp = it;
      for(; tmp!=a[i].end()&&tmp->first==it->first; tmp++)
      {
        k++;
      }
      if(k==2)
      {
        tmp--;
        cout << a[i].begin()->second << " " << tmp->second << "\n";
      }
      else
      {
        cout << "?\n";
      }
    }else
    if(k==2)
    {
      it--;
      cout << a[i].begin()->second << " " << it->second << "\n";
    }
    else
    {
      cout << "?\n";
    }
  }
  return 0;
}
