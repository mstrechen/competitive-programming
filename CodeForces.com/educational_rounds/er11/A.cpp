#include <iostream>

using namespace std;

int a[1000], b[10000];

const int prime_1 = 999999937, prime_2 = 999999929;
int gcd(int a, int b)
{
	if(b==0) return a;
	return(gcd(b, a%b));
}
int main(){
	ios::sync_with_stdio(false);
	int n, k = 1;
	cin >> n;
	for(int i = 0; i< n; i++)
	{
		cin >> a[i];
	}
	b[0] = a[0];
	for(int i = 1; i<n; i++)
	{
		if(gcd(a[i-1], a[i])>1)
		{
			if(a[i]!=prime_1&&a[i-1]!=prime_1)
			{
				b[k++] = prime_1;
				b[k++] = a[i];
			}
			else
			if(a[i]!=prime_2&&a[i-1]!=prime_2)
			{
				b[k++] = prime_2;
				b[k++] = a[i];
			}
			else
			{
				b[k++] = 2;
				b[k++] = a[i];
			}
		}
		else
		{
			b[k++] = a[i];
		}
	}
	cout << k-n << '\n';
	for(int i = 0; i<k; i++) cout << b[i] << ' ';
	return 0;
}