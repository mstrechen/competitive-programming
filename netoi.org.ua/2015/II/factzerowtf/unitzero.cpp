#include <iostream>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	long long summ = 0, summ1=0;
	int n;
	cin >> n;
	for(int i=2; i<n; i++)
	{
		summ+=((n/i - 1)*(n/i)/2)*i + (n/i)*(n % i) ;
		
	}	
	cout << summ;
	
	for(int i=2; i<n; i++)
	{
		summ+=((n/i - 1)*(n/i)/2)*i + (n/i)*(n % i) ;
		
	}	
return 0;