#include <iostream>
#include <fstream>
using namespace std;
unsigned long long pref(unsigned long long a)
{
	
	unsigned long long ans = 0;
	if(a<2)
	{
		return 0;
	}
	if(a == 2)
	{
		return 1;
	}
	ans = 1;
	for(unsigned long long i = 1; i<a*2; i=i*2+1)
	{
		for(unsigned long long j = 1; j<i/2; j*=2)
		{
			if((i-j) <=a)
			{
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	unsigned long long a,b;
	//ifstream cin("inputb.txt");
	cin >> a >> b;
	cout << pref(b)-pref(a-1);
	return 0;
}