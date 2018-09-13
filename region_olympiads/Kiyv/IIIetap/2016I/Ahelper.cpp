#include <iostream>

using namespace std;

bool checkPrime(int n)
{
	for(int i = 2; i*i<=n; i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int i = 0;
	for(int i = 2;i<=40000; i++)
	{
		if(checkPrime(i))
		{
			cout << i<<',';
		}
	}
	return 0;
}