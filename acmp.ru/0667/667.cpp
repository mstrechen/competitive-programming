#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin >> n >>m >> k;
	if(k<3)
	{
		cout << 0;
	}
	else
	{
		if(m/2>=(n-1)/(k-2) + 1 ){cout << (n+m-1)/k+1;}
		else cout << 0;
	}
	return 0;
}