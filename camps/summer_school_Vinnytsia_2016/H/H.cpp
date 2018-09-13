#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	long long n, m, t, k;
	long long tmp;
	
	cin >> n >> m >> t >> k;
	
	double area = m + (t+n)/2.0 - 1;
	long long fillingSpeed = m-3*t;
	
	cout.precision(15);
	
	if(k == 0)
		cout << fixed << 0;
	else
	if(fillingSpeed>0)
		cout << fixed << area*k/fillingSpeed;
	else
		cout << -1;
	
	return 0;
}