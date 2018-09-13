#include<iostream>
#include<fstream>
#include<vector>
#include<map>

using namespace std;


map<pair<vector<int>, vector<int> >, int > _Q;

vector<int> a(20,0), b(20,0);
vector<int> A(20,0), B(20,0);

vector<pair<int,int> > possible;
int n,m;

bool rec(int _i)
{
  if(_Q[make_pair(A,B)])
  {
    return _Q[make_pair(A,B)]-1;
  }
  bool win = 0;
  int group1 = 0;
  int group2 = 0;
  int j = 0;

  for(int i = 0; i<n; i++)
  {
    if(A[i])
    {
      group1++;
    }
    else
    {
      group2 = 0;
      j = 0;
      while(group2<group1)
      {
        group2+=B[j];
        j++;
      }
      while(group2==group1&&j<m)
      {
        if(B[j])
          group2++;
        else
        {
          if(a[i]==b[j])
          {
            A[i] = 1;
            B[j] = 1;
            if(_i==0)
            {
              if(!rec(_i+1))
              {
                possible.push_back(make_pair(i,j));
              }
            }
            else
            {
              win|=!rec(_i+1);
            }
            A[i] = 0;
            B[j] = 0;
          }
        }
        j++;
      }
    }
  }
  _Q[make_pair(A,B)] = win+1;
  return win;
}
int main()
{
  ifstream cin("game.in");
  ofstream cout("game.out");
  cin >> n >> m;

  for(int i = 0; i<n; i++)
    cin >> a[i];
  for(int i = 0; i<m; i++)
    cin >> b[i];
  rec(0);
  if(possible.size()==0)
    cout << "LOSE";
  else
    cout << "WIN";
  for(int i = 0; i<possible.size(); i++)
  {
    cout << '\n' << possible[i].first << ' ' << possible[i].second;
  }
  return 0;
}
