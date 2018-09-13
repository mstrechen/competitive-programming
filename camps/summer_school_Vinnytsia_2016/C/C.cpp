#include<iostream>

using namespace std;

long long min(long long a, long long b)
{
	return a>b?b:a;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	long long firstMax, secondMax, 
			  firstMin, secondMin;
	long long tmp;
	
	cin >> n;
	cin >> firstMax >> secondMax;
	
	if(firstMax<secondMax)
		swap(firstMax, secondMax);
	secondMin = firstMax;
	firstMin = secondMax;
	
	for(int i = 2; i<n; i++)
	{
		cin >> tmp;
		
		if(tmp>firstMax)
		{
			secondMax = firstMax;
			firstMax = tmp;
		}
		else
		if(tmp>secondMax)
		{
			secondMax = tmp;
		}
		if(tmp<firstMin)
		{
			secondMin = firstMin;
			firstMin = tmp;
		}
		else
		if(tmp<secondMin)
		{
			secondMin = tmp;
		}
	}
	
	cout << min(min(firstMax*secondMax,
					firstMin*secondMin), 
					firstMax*firstMin);
	
	return 0;
}