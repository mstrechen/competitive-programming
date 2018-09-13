#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	long long 	summ = 0,
				summOfSquares = 0;
	long long a, b;
	
	cin >> n;
	
	for(int i = 0; i<n; i++)
	{
		cin >> a >> b;
		summ+=a-b;
		summOfSquares+=(a-b)*(a+b);
	}
	
	cout << ((summOfSquares/summ)+summ)/2 << ' ' << ((summOfSquares/summ)-summ)/2;
	
	
	return 0;
}