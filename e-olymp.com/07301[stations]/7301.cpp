#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
bool isMore(long long a, long long b)
{
	return a>b;	
}


long long spans[2048], stops[2048];


int main(){
	
	int n,m,tmp;
	
	long long summ=0,summInWay=0;
	scanf("%d%d",&n,&m);
	for(int i = 0; i<n; i++)
	{
		stops[i] = 0;
	}
	
	
	
	for(int i = 1; i<n; i++)
	{
		for(int j = 0; j<i; j++)
		{
			scanf("%d",&tmp);
			summ+=tmp;
			stops[j]+=tmp;
			stops[i]-=tmp;
		}
		
	}
	for(int i  = 0; i<n; i++)
	{
		summInWay+=stops[i];
		spans[i] = summInWay;
	}
	sort(spans,spans+n-1,isMore);
	for(int i = 0; i<m-1; i++)
	{
		summ+=spans[i];
	}
	cout << summ;
	return 0;
}