#include<iostream>
#include<set>
#include<string>

using namespace std;

struct point
{
  int x,y;
} a[2000];

bool isRightRotate(point a, point b, point c)
{
  return ((a.y>b.y)&&(b.x<c.x))
        ||((a.x<b.x)&&(b.y<c.y))
        ||((a.y<b.y)&&(b.x>c.x))
        ||((a.x>b.x)&&(b.y>c.y));
}

int main()
{

  //freopen("inp.txt", "r", stdin);
  ios::sync_with_stdio(false);
  int n,k = 0;
  cin >> n;
  for(int i = 0; i<n; i++)
  {
    cin >> a[i].x >> a[i].y;
  }
  a[n] = a[0];
  for(int i = 1; i<n; i++)
  {
    k+=isRightRotate(a[i-1],a[i],a[i+1]);
  }
  cout << k;
  return 0;
}
