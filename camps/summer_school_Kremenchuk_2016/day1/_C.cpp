
#include<iostream>
#include <algorithm>

using namespace std;


pair<long long,long long> a[100500];
pair<int, long long> dyn[100500];


long long abs(long long a, long long speed, int n)
{
  return a>0?a:-a;
}
int sol(int flag)
{
  dyn[0].first = 0;
  dyn[0].second = 0;
  for(int i = 1; i<=n; i++)
  {
    dyn[i].second = 0;
    for(int j = i-1; j>=0 && abs(a[i].second-a[dyn[j].second].second)>
                          speed*(a[i].first-a[dyn[j].second].first); j--)
      if(j>=0)
        dyn[i].first = dyn[j].first + 1;
			else
			dyn[i].first = hasTransport;

		for(j=i;j>0 && dyn[j].first<dyn[j-1].first; j--)
			swap(dyn[j],dyn[j-1]);
  }
	return dyn[n].X;
}
int main()
{

  long long speed;
  int n;

  cin >> n;
  for(int i = 0; i<n; i++)
    cin >> a[i].second >> a[i].first;
  cin >> begin;

  a[n].first = 0;
  a[n].second = 0;
  sort(a,a+n+1);
  cout << sol(1,speed, n);
  for(i=1;i<=n;)
  {
		if(abs(a[i].second)>speed*a[i].first) {
			swap(a[i],a[n]);
			n--;
		}
		else
    {
			i++;
		}
	}
	sort(a,a+n+1);
	cout << ' ' << sol(0,speed, n);

  return 0;

}
