#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int primeNumbers[13] = 			 {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
bool myComp(int a, int b)
{
	return a>b;
}
const long long MAX_SIZE_OF_N = 1E15+1;
bool checkPow(int n, int k)
{
	long long tmp = 1;
	for(int i = 1; i<k; i++)
	{
		tmp*=n;
		if(tmp>MAX_SIZE_OF_N)
		{
			return false;
		}
	}
	return true;
}
bool myPow(int a,int b,int powOfA,int powOfB,int k)
{
	long long a1 = 1,b1 = 1;
	for(int i = powOfA*k-1; i>=0; i--)
	{
		a1*=a;
		if(a1>MAX_SIZE_OF_N)
		{
			return false;
		}
	}
	for(int i = powOfB*k-1;i>=0; i--)
	{
		b1*=b;
		if(b1>MAX_SIZE_OF_N)
		{
			return true;
		}
	}
	return a1<b1;
}
long long some_action(int n, int i)
{
	int listOfFactors[13];
	for(int i = 2; i<=n;)
	{
		if(n%i==0)
		{
			listOfFactors[sizeOfListOfFactors] = i;
			sizeOfListOfFactors++;
			n/=i;
		}
		else
		{
				i++;
		}
	}
	if()
	for(int j = 0; j<(1 <<sizeOfListOfFactors) )
}
int main(){
	ios::sync_with_stdio(false);
	int listOfFactors[13];
	int d,sizeOfListOfFactors=0;
	long long n = 1;
	cin >> n;
	listOfMultipleOfPowers[0]*=n;
	for(int i = 2; i<=n;)
	{
		if(n%i==0)
		{
			listOfFactors[sizeOfListOfFactors] = i;
			sizeOfListOfFactors++;
			n/=i;
		}
		else
		{
				i++;
		}
	}
	
	cout << some_action(n,0);
	return 0;
}