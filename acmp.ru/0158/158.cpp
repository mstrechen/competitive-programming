#include <iostream>

using namespace std;

long long solve(int x, int k)
{
	if(x==0) return 1;
	if(k==1) return 1;
	long long ans=0;
	for(int i = 0; i<=x; i++)
	ans+=solve(x-i, k-1);
	return ans;
}
int main(){
    ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	cout << solve(n/5,k+1);
	return 0;
}