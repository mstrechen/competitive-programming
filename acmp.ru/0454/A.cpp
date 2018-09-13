#include<iostream>
#include<fstream>
#include<vector>
#include<bitset>
using namespace std;

int main()
{
  vector<int> a(5000);
  ofstream cout("hm1.txt");
  for(int i = 2; i<10000; i++)
  {
    a.clear();

    for(int j = 1; j<i; j++)
    {
      a.push_back(j);
    }
    int k = 0;
    while(a.size()>1)
    {
      if(k%2==0)
      {
        for(int j = 0; j<a.size(); j++)
        {
          a.erase(a.begin()+j);
        }
      }
      else
      {
        for(int j = 1; j<a.size(); j++)
        {
          a.erase(a.begin()+j);
        }
      }
      k++;
    }
    cout << i-1 << ' ' << a[0] << '\n';
  }

  return 0;
}
