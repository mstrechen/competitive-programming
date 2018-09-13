#include<iostream>
#include<vector>

using namespace std;

long long intPower(long long a, int x)
{
	long long result = 1;
	for(int i = 0; i<x; i++)
	{
		result*=a;
	}
	return result;
}

void factorize(long long n, vector<long long> & dividers, vector<int> & powers)
{
	dividers.clear();
	powers.clear();
	
	if(n%2==0)
	{
		dividers.push_back(2);
		powers.push_back(0);
		while(n%2==0)
		{
			powers[powers.size()-1]++;
			n/=2;
		}
	}
	
	for(long long i = 3; i*i<=n; i+=2)
	{
		if(n%i==0)
		{
			dividers.push_back(i);
			powers.push_back(0);
			while(n%i==0)
			{
				powers[powers.size()-1]++;
				n/=i;
			}
		}
	}
	
	if(n>1)
	{
		dividers.push_back(n);
		powers.push_back(1);
	}
}
int main()
{
	long long n;
	vector<long long> dividers;
	vector<int> powers;
	
	cin >> n;
	
	factorize(n, dividers, powers);
	
	bool somethingIsChanged = 0;
	
	for(unsigned int i = 0; i<powers.size(); i++)
	{
		
		if(powers[i]%3)
		{
			somethingIsChanged = 1;
			powers[i]+= 3 - powers[i]%3;
		}
	}
	
	n = 1;
	for(unsigned int i = 0; i<dividers.size(); i++)
	{
		n*=intPower(dividers[i], powers[i]);
	}
	cout << n;
	
	return 0;
}