#include <iostream>

using namespace std;

int a[501000];

int main(){
	ios::sync_with_stdio(false);
	int n, k, currentK = 0, l = 0, r = 0;
	int max_l = 0, max_r = -1, maxLength = 0;
	cin >> n >> k;
	for(int i = 0; i<n; i++) cin >> a[i];
	
	for(;r<n;)
	{
		currentK+=1-a[r++];
		while(currentK>k)
		{
			currentK-=1-a[l++];
		}
		if(r-l>maxLength)
		{
			maxLength = r-l;
			max_l = l;
			max_r = r;
		}
	}
	cout << maxLength << '\n';
	for(int i = 0; i<n; i++)
	{
		if(max_l<=i&&i<max_r)
		{
			cout << 1 << ' ';
		}
		else
		{
			cout << a[i] << ' ';
		}
	}
	return 0;
}