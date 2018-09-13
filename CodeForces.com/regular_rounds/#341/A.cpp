#include <iostream>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	int n,tmp,minimal = 2e9;
	__int64 summ = 0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> tmp;
		summ+=tmp;
		if(tmp%2==1)
		{
			minimal = min(minimal,tmp);
		}
	}
	if(summ%2==0)
	{
		cout << summ;
	}
	else if(minimal==(int)2e9)
	{
		cout <<  0;
	}
	else
	{
		cout << summ - minimal;
	}
		
	return 0;
}