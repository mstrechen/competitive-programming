#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	
	cin >> n;
	
	if(n<=4)
	{
		cout << -1;
	}
	else
	if(n%2==1)
	{
		int k = (n-1)/2;
		int current = 0;
		for(int i = 0; i<n; i++)
		{
			cout << current+1 << ' ' << (current+k)%n+1 << '\n';
			current+=k;
			current%=n;
		}
	}
	else
	{
		int k = n/2;
		
		for(int i = 0; i<k; i++)
			cout << i*2+1 << ' ' << ((i+1)*2)%n+1 << '\n';
		
		for(int i = 0; i<k; i++)
			cout << i*2+2 << ' ' << ((i+1)*2)%n+2 << '\n';
	}
	
	return 0;
}