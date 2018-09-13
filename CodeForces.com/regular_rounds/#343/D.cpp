#include <iostream>

using namespace std;
const long long infinite = 1e15;
long long  primePies[200000], dyn[200000];
const double pi = 3.141592653589793238462643;

int main(){
	ios::sync_with_stdio(false);
	int n, tmp1,tmp2;
	cin >> n;
	dyn[0] = -infinite;
	for(int i = 0; i<n; i++)
	{
		cin >> tmp1 >> tmp2;
		dyn[i+1] = infinite;
		primePies = infinite - tmp1*tmp1*tmp2;
	}
	int maxj = 0;
	for(int i = 0; i<n; i++)
	{
		long long j = (long long)(lower_bound(dyn, dyn+n, primePies[i])-n);
		if(dyn[j-1] < primePies[i] && primePies[i] < dyn[j])
		{
			dyn[j] = primePies[i];
			maxj = j;
		}
		
	}
	cout << maxj
	return 0;
}