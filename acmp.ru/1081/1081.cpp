#include <iostream>

using namespace std;

long long a[100500];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	
	cin >> n;
	
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
		a[i]+=a[i-1];
	}
	cin >> m;
	
	int x,y;
	for(int i = 0; i<m; i++)
	{
		cin >> x >> y;
		cout << a[y]-a[x-1] << ' ';
	}
	
	
	return 0;
}