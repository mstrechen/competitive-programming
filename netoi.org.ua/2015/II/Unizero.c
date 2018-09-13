#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	long long precalc[100];
	long long summ = 0, summ1=0;
	long long n;
	
	for(n=50000;n<5000000; n++){
	
	for(int i=n/2; i>1; i--)
	{
		
		summ+=((n/i - 1)*(n/i)/2)*i + (n/i)*(n % i) ;
	}	
	for(int i=n/2+1; i<n; i++)
	{
		summ+=((n/i - 1)*(n/i)/2)*i;
		
	}	
	cout << << summ +((n-1)/2)*((n-1)/2+1)/2; 
	}
return 0;
}