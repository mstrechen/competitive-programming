#include<iostream>

using namespace std;


int main()
{
	long long n;
	
	cin >> n;
	
	if(n==2||n%2==1)
		cout << 2;
	else
		cout << 1;
	
	return 0;
}