#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int maxL =0 ;
	int n,tmp;
	long long s = 0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin>>tmp;
		maxL = max(maxL, tmp);
		s+=tmp;
	}
	cout << 2*maxL - s + 1;
	return 0;
}