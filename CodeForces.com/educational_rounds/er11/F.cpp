#include <iostream>

using namespace std;

int a[200000];
long long prefix[200000];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cin >> a[0];
	prefix[0] = a[0];
	long long currentSumm = a[0], all = a[0]*(n+1);
	for(int i = 1; i<n; i++)
	{
		cin >> a[i];
		prefix[i] = a[i] + prefix[i-1];
		currentSumm+=prefix[i];
		all+=a[i]*(n+1);
	}
	
	currentSumm = all-currentSumm;
	long long maxSumm = currentSumm;
	int first = 0;
	for(int i = 0; i<n; i++)
	{
		currentSumm-=prefix[n-1];
		if(i>0)currentSumm+=prefix[i-1];
		if(currentSumm>maxSumm)
		{
			maxSumm = currentSumm;
			first = i+1;
		}
	}
	for(int i = n-1; i>first; i--)
	{
		currentSumm-=a[i]*(i-first+1);
		if(currentSumm>maxSumm)
		{
			maxSumm = currentSumm;
		}
	}
	cout << maxSumm;
	return 0;
}