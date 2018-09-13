#include<iostream>
#include<fstream>
#include<vector>


using namespace std;

struct longNumber
{
  vector<int> _num;
  longNumber(long long a = 0)
  {
    while(a!=0)
    {
      _num.push_back(a%10);
      a/=10;
    }
  }
  int size()
  {
    return _num.size();
  }

  void setSize(int n)
  {
    _num.assign(n,0);
  }

  void _normalize()
  {
    while(_num[_num.size()-1]==0)
      _num.pop_back();
  }

  void print()
  {
    if(size()==0)
      cout << 0;
    else
      for(int i = size()-1; i>=0; i--)
        cout << _num[i];

  }

  int & operator [](int a)
  {
    return _num[a];
  }

  longNumber operator +(longNumber a)
  {
    longNumber tmp(0);
    int cameFromBack = 0;
    tmp.setSize(max(this->size(), a.size())+1);
    for(int i = 0; i<tmp.size(); i++)
    {
      tmp[i] = cameFromBack;
      if(a.size()>i)
        tmp[i]+=a[i];
      if(this->size()>i)
        tmp[i]+=a[i];
      cameFromBack = tmp[i]/10;
      tmp[i]%=10;
    }
    tmp._normalize();
    return tmp;
  }

};

int main()
{
  int n;
  int k;
  cin >> n;
  longNumber a(n);
  a.print();
  return 0;
}
