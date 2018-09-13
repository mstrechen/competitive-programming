#include<iostream>

using namespace std;

long long getSummOfDigits(long long a)
{
	long long res = 0;
	while(a!=0)
	{
		res+=a%10;
		a/=10;
	}
	return res;
}

long long getCountForPrefix(long long a)
{
	if(a<=0)
		return 0;
	
	long long lastDigit = a%10;
	
	return getCountForPrefix(a/10-1)*10 + 
		   getSummOfDigits(a/10)*(lastDigit+1) + 
		   lastDigit*(lastDigit+1)/2 + 
		   (a/10)*45;
}

int main()
{
	ios::sync_with_stdio(false);
	
	long long l, r;
	
	cin >> l >> r;
	cout << getCountForPrefix(r) - getCountForPrefix(l-1);
	
	return 0;
}