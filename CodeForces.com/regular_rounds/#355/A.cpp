#include<iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n, m, tmp;
  int summ = 0;
  cin >> n >> m;
  for(int i = 0; i<n; i++)
  {
    cin >> tmp;
    summ+=tmp>m?2:1;
  }
  cout << summ;

  return 0;
}
