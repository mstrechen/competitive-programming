#include <iostream>

using namespace std;
double flowers[100001];
int main(){
	ios::sync_with_stdio(false);
	int n,tmp1,tmp2,p;
	double all,ok;
	double expected = 0;
	cin >> n >> p;
	for(int i = 0; i<n; i++)
	{
		cin >> tmp1 >> tmp2;
		all = tmp2-tmp1+1;
		ok = tmp2/p - (tmp1-1)/p;
		flowers[i] = (double)(ok/all);
	}
	for(int i=1; i<n; i++)
	{
		expected+=2000*(flowers[i]+flowers[i-1]-flowers[i]*flowers[i-1]);
	}
	expected+=2000*(flowers[0]+flowers[n-1]-flowers[0]*flowers[n-1]);
	cout.precision(8);
	cout << (fixed) <<expected;
	return 0;
}