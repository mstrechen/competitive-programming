#include <iostream>
#include <cmath>
using namespace std;

const long long modular = 1E9+7;
int dividers[100000];
int main(){
	ios::sync_with_stdio(false);
	int n,k,tmp;
	long long result = 1, pow10;
	cin >> n >> k;
	pow10 = pow(10,k-1);
	for(int i = 0; i<n/k; i++){
	cin >> dividers[i];}
	for(int i = 0; i<n/k; i++)
	{
		cin >> tmp;
		if(tmp>0)
		{
			result*=((pow10*10-1)/dividers[i] - (pow10*(tmp+1)-1)/dividers[i] + (pow10*tmp-1)/dividers[i]+1);
		}
		else
		{
			result*=(pow10*10-1)/dividers[i]-(pow10-1)/dividers[i];
		}
		result = result % modular;	
		
	}
	cout << result;
	return 0;
}