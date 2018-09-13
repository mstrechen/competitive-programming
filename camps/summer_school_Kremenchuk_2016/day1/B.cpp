#include<iostream>
#include<set>

using namespace std;


set<int> a;
set<int>::iterator it;
int main()
{
  int n;
  int left = 0, right = 0;
  int choice;

  char c, currentVar = 'N';
  cin >> n;

  for(int i = 1; i<=n; i++)
    a.insert(i);
  for(int i = 0; i<n; i++)
  {
    cin >> c;
    if(c==currentVar)
    {
        if(left>right)
        {
          it = a.lower_bound(left-right);
          if(it!=a.begin())
          {
            --it;
            choice = *it;
            a.erase(choice);
            cout << 'R' << ' ' << choice << '\n';
            right+=choice;
          }
          else
          {
            choice = *(a.begin());
            a.erase(choice);
            cout << 'L' << ' ' << choice << '\n';
            left+=choice;
          }
        }
        else
        {
          it = a.lower_bound(right-left);
          if(it!=a.begin())
          {
            --it;
            choice = *it;
            a.erase(choice);
            cout << 'L' << ' ' << choice << '\n';
            left+=choice;
          }
          else
          {
            choice = *(a.begin());
            a.erase(choice);
            cout << 'R' << ' ' << choice << '\n';
            right+=choice;
          }

        }
    }
    else
    {
        if(left>right)
        {
           choice = *a.upper_bound(left-right);
           a.erase(choice);
           right+=choice;
           cout << 'R' << ' '<< choice << '\n';
        }
        else
        {
           choice = *a.upper_bound(right-left);
           a.erase(choice);
           left+=choice;
           cout << 'L' << ' '<<choice << '\n';

        }
    }
    currentVar = c;
  }
  return 0;
}
