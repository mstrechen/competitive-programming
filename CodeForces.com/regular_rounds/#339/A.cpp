#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	unsigned long long i,l,r,k,count=0;
	cin >> l >> r >> k;
	for(i = 1; i<=r;i*=k)
	{
		if(i>=l)
		{cout << i << ' ';
		count++;
		}
		if((i*k)/k!=i)
		{
			break; 
		}
	}
	if(count==0)
	{
		cout << -1;
	}
	return 0;
}