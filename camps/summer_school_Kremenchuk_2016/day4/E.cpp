#include<iostream>

using namespace std;

int cnt[1500];

int saved[1500][1500];


int rec(int _i, int cropped)
{
  if(saved[_i][cropped]!=-1)
    return saved[_i][cropped];
  int res = rec(_i-1, cnt[_i]+cropped)+cnt[_i];
  if(cnt[_i]+cropped>=4)
    res = min(res, rec(_i-1,cnt[_i]+cropped-4));
  saved[_i][cropped] = res;
  return res;
}

int main()
{
  int n;
  cin >> n;
  int tmp;
  for(int i = 0; i<n; i++)
  {
    cin >> tmp;
    cnt[tmp]++;
    cnt[tmp]%=4;
  }
  for(int i = 1; i<1500; i++)
    for(int j = 0; j<1500; j++)
      saved[i][j] = -1;
  cout << rec(100,0);

  return 0;
}
