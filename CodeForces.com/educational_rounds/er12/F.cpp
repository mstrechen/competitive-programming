#include <iostream>
using namespace std;

long long primes[1000001];
bool field[2000002];
int k = 0;

int main(){
	ios::sync_with_stdio(false);
	long long n;
	long long answer = 0;
	field[1] = 1;
	cin >> n;
	
	for(int i = 2; i<1500; i++)
	{
		if(!field[i])
		{
			primes[k++] = i;
			for(int j = 2; i*j < 2000001; j++)
			{
				field[i*j] = 1;
			}
		}
	}
	for(int i = primes[k-1]; i<2000001; i++)if(!field[i])primes[k++] = i;
	cout << k;
	for(long long  i = 0; i<k; i++)
	{
		if(primes[i]*primes[i]<=n&&primes[i]*primes[i]*primes[i]<=n) answer++;
		for(int j = i+1; j<k; j++)
		{
			if(primes[i]*primes[j]<=n) answer++;
		}
	}
	cout << answer;
		
	return 0;
}