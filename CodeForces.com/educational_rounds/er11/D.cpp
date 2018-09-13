#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

pair<int,int> a[2000];

multiset<pair<int,int> > setOfVectors;
int main(){
	ios::sync_with_stdio(false);
	int n,answer = 0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> a[i].first >> a[i].second;		
	}
	sort(a,a+n);
	for(int i = 0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			answer+=setOfVectors.count(make_pair(a[j].first-a[i].first, a[j].second-a[i].second));
			setOfVectors.insert(make_pair(a[j].first-a[i].first, a[j].second-a[i].second));
		}
	}
	cout << answer/2;
	return 0;
}