#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if(a&&b)
		return gcd(b%a, a);
	return a+b;
}

int main(){
	
	int n, m;
	
	cin >> n >> m;
	cout << 1+gcd(n-1,m-1);
	
	return 0;
}