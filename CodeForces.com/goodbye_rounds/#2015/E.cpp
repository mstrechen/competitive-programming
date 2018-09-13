#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long pref(unsigned long long a)
{
	unsigned long long ans = 0;
	for(int i = 1; i<a*2; i*=2+1)
	{
		for(int j = 1; j<i/2; j*=2)
		{
			if((i-j) < a)
			{
				ans++;
				cout << i <<' '<<j;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cout<< pref(5);
	return 0;
}