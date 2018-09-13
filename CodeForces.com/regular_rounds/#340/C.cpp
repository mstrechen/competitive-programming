#include <iostream>
#include <algorithm>

using namespace std;

struct someStruct{
	long long a,b;
} d[3000];

long long mini(long long a, long long b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
long long maxi(long long a, long long b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int vladilove(someStruct a, someStruct b)
{
	if(a.a!=b.a){
	return a.a<b.a;
		
	}
	else
	{
		return a.b>b.b;
	}
}
long long const MAGIC_CONST = 922337203685477580;
int main(){
	ios::sync_with_stdio(false);
	long long n,minSumm=MAGIC_CONST, minTmp, x1,x2,y1,y2,tmp1x,tmp1y,rad1,rad2;
	
	cin >> n;
	cin >> x1 >> y1 >> x2>>y2;
	
	for(int i = 0; i<n; i++)
	{
		cin >> tmp1x >> tmp1y;
		d[i].a = (x1-tmp1x)*(x1-tmp1x)+(y1-tmp1y)*(y1-tmp1y);
		d[i].b = (x2-tmp1x)*(x2-tmp1x)+(y2-tmp1y)*(y2-tmp1y);
		
	}
	
	sort(d,d+n, vladilove);
	for(int i = 0; i<=n; i++)
	{
		minTmp = 0;
		for(int j = i; j<n; j++)
		{
			minTmp = maxi(minTmp, d[j].b);
		}
		if(i == n)
		{
			minSumm = mini(minSumm,d[n-1].a);
		}
		else
		{
			if(i>0)
			{
				minSumm = mini(minSumm,d[i-1].a+minTmp);
			}
			else
			{
				minSumm = mini(minSumm,minTmp);
			}
		}
	}
	cout << minSumm;
	return 0;
}