
#include <iostream>
#include<ctime>
using namespace std;
int main(){
	long long summ=0;
	long long n;
	long long tmp;
	cin >> n;
	double be = clock();
	for(int i=n/2; i>1; i--)
	{
		summ+=((n/i - 1)*(n/i)>>1)*i + (n/i)*(n % i) ;
		
		

	}	
	for(int i=n/2+1; i<n; i++)
	{
		summ+=((n/i - 1)*(n/i)/2)*i;
		
	}	
	cout << summ+((n-1)/2)*((n-1)/2+1)/2; 
	double en = clock();
	cout <<" TIME:"<<(en-be)/CLOCKS_PER_SEC;
return 0;
}