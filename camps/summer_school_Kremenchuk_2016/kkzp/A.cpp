#include<iostream>


using namespace std;

int polygon[2000];
int sides[2000];

int main()
{
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  for(int _i = 0; _i<n; _i++)
  {
    a[_i] = 1;
    int currM = m-i;
    for(int i = 0; i<n; i++)
      sides[i] = 0;
    int maxDiff = 0, minDiff = 2;
    for(int i = 0; i<n; i++)
    {
      maxDiff = max(polygon[i]+polygon[(i+1)%n], maxDiff);
      minDiff = min(polygon[i]+polygon[(i+1)%n], minDiff);
    }
    for(int i = )
  }
  return 0;
}
