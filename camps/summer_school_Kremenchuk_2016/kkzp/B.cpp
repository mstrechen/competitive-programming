#include<iostream>
#include<set>
#include<vector>

using namespace std;

const int MAXN = 40001;
vector<int> _A[100500], _B[100500];

vector<int> * A = _A;
vector<int> * B = _B;

int problems[50][50];

int last(const vector<int> & a)
{
  if(a.size()==0)
    return 100500;
  return a[a.size()-1];
}

int main()
{
  ios::sync_with_stdio(false);
  int S;
  int k, n;
  cin >> S >> k >> n;

  int tmp;
  k--;

  for(int i = 0; i<n; i++)
  {
    cin >> tmp;
    A[tmp] = vector<int>(1,tmp);
    for(int j = 0; j<k; j++)
    {
      cin >> problems[j][i];
    }
  }

  for(int _i = 0; _i<k; _i++)
  {
    for(int i = 1; i<MAXN; i++)
    {
      B[i].clear();
    }
    for(int i = 1; i<MAXN; i++)
    if(A[i].size())
    {
      for(int j = 0; j<n; j++)
      {
        if(problems[_i][j]>=last(A[i]))
        {
          A[i].push_back(problems[_i][j]);
          B[i+problems[_i][j]] = A[i];
          A[i].pop_back();
        }
      }
    }
    swap(A,B);
  }
  if(A[S].size())
  {
    cout << "YES\n";
    for(int i = 0; i<A[S].size(); i++)
    {
      cout << A[S][i] << ' ';
    }
  }
  else
  {
    cout << "NO";
  }


  return 0;
}
