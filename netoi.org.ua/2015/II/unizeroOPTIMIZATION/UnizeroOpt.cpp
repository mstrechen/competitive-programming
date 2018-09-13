
#include <iostream>
#include <ctime>
using namespace std;
int main(){
	long long summ=0,summ1;
	long long n;
	cin >> n;
	n--;
	//n = 5000000;
	double be = clock();
	for(int i = n; i>1; i--)
	{
		summ1 = 0;
		for (int j = i/2; j>0; j--)
		{
			summ1+=(i-j)/j;
		}
		summ+=summ1;
	}
	cout << summ; 
	double en = clock();
	//cout << 3; 
	cout << "\n" << (en-be)/CLOCKS_PER_SEC;
return 0;
}