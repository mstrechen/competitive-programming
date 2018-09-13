#include<iostream>

using namespace std;

int a[100001];
int main()
{
  ios::sync_with_stdio(false);
  long long n, h, k;
  long long time = 0;
  long long current = 0;
  long long tmp;

  cin >> n >> h >> k;
  for(int i = 0; i<n; i++)
    cin >> a[i];

  int l = 0;
  while(l!=n)
  {
    if(h >= a[l]+current)
    {
      while(l!=n&&h >= a[l]+current)
        current+=a[l++];
      current-=min(k, current);
      time++;
    }
    else
    {
      tmp = (a[l]+current-h-1)/k + 1;
      time+=tmp;
      current-=min(current, k*tmp);
    }
  }
  if(current)
  time+=(current-1)/k+1;

  cout << time;


  return 0;
}
