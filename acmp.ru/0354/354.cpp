#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	long long dividers[100];
	long long n,countOfDivisiders=0;
	
	cin >> n;
	long long i = 2;
	while(n>1 && i*i<=n)
	{
		while(n % i == 0 && n>1)
		{
			dividers[countOfDivisiders] = i;
			countOfDivisiders++;
			n /=i;
		}
		i++;
	}
	if(n>1)
	{
		dividers[countOfDivisiders] = n;
		countOfDivisiders++;
	}
	cout << dividers[0];
	for(int i = 1; i<countOfDivisiders; i++)
	{
		cout << '*' << dividers[i];
	}
	
return 0;
} 
//2*2*2*2*2*3*3*5*5*5*7*11*13*17*19*23 - 267711444000
//2*2*2*2*2*3*3*3*5*5*7*11*13*17*19*23 - 
//2*2*3*3*5*7*11*13*17*19*23*29*31