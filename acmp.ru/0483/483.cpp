#include<iostream>

using namespace std;

int binaryNum[32];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k = 0,len = 0;
	char c;
	cin >> n;
	for(int i = n-1; i>=0; i--)
	{
		cin >> c;
		k+=c=='1';
	}
	do
	{
		binaryNum[len++] = k&1;
		k>>=1;
	}
	while(k>0);
	for(int i = len-1; i >= 0; i--)
	{
		cout << binaryNum[i];
	}
	
}