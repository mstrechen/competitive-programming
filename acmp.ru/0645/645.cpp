#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int n, beauty=1;
	cin >> n;
	for(int i = 2; i*i<=n; i++)
	{
		if(n/i-i+n-i*(n/i)<n/beauty-beauty+n-beauty*(n/beauty))
		{
			beauty =  i;
		}
	}
	cout << beauty <<' ' << n/beauty;
	return 0;
}