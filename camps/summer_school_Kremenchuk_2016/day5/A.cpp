#include<iostream>
#include<fstream>
#include<vector>
#include<string>


using namespace std;

struct SO_BIG_INT
{
  vector<int> _digits;
  SO_BIG_INT(int a = 0)
  {
    this->_digits.clear();
    while(a>0)
    {
      this->_digits.push_back(a%10);
      a/=10;
    }
  }
  void operator()(int a = 0)
  {
    this->_digits.clear();
    while(a>0)
    {
      this->_digits.push_back(a%10);
      a/=10;
    }
  }
  void operator+=(const SO_BIG_INT & a)
  {
    int n =  a._digits.size();
    if(this->_digits.size()<a._digits.size())
    {
      this->_digits.reserve(a._digits.size()+1);
      for(int i = this->_digits.size(); i<a._digits.size(); i++)
      {
        this->_digits.push_back(0);
      }
    }
    this->_digits.push_back(0);
    for(int i = 0; i<n; i++)
    {
      this->_digits[i]+=a._digits[i];
    }
    int fromBack = 0;
    for(int i = 0; i<this->_digits.size(); i++)
    {
      this->_digits[i]+=fromBack;
      fromBack = (this->_digits[i]/10);
      this->_digits[i]%=10;
    }
    if(this->_digits[this->_digits.size()-1]==0)
    {
      this->_digits.pop_back();
    }
  }
  void operator *=(int a)
  {
    for(int i = 0; i<this->_digits.size(); i++)
    {
      _digits[i]*=a;
    }
    int cameFromBack = 0;
    for(int i = 0; i<this->_digits.size(); i++)
    {
      this->_digits[i]+=cameFromBack;
      cameFromBack = this->_digits[i]/10;
      this->_digits[i]%=10;
    }
    while(cameFromBack)
    {
      this->_digits.push_back(cameFromBack%10);
      cameFromBack/=10;
    }
  }
  void print()
  {
    if(this->_digits.size() == 0)
      cout << 0;
    else
    for(int i = this->_digits.size()-1; i>=0; i--)
      cout << this->_digits[i];
  }


};

int dividers[5000];

int main()
{
  int n;
  ifstream in("convol.in");
  freopen("convol.out", "w", stdout);


  in >> n;
  n--;

  for(int i = n+1; i<=n*2; i++)
  {
    int curr = i;
    for(int j = 2; j*j<=curr; j++)
    {
      while(curr%j==0)
      {
        dividers[j]++;
        curr/=j;
      }
    }
    dividers[curr]++;
  }
  for(int i = 2; i<=n; i++)
  {
    int curr = i;
    for(int j = 2; j*j<=curr; j++)
    {
      while(curr%j==0)
      {
        dividers[j]--;
        curr/=j;
      }
    }
    dividers[curr]--;
  }

  SO_BIG_INT calculated(1);
  for(int i = 1; i<5000; i++)
  {
    for(int j = 0; j<dividers[i]; j++)
    {
      calculated*=i;
    }
  }
  calculated.print();


  return 0;
}
