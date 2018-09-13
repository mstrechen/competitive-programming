#include <iostream>

using namespace std;
unsigned long long a,b,count=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b;
	for(unsigned long long i = 1; i<a; i++)
	{
		if((i^(a-i))==b)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}