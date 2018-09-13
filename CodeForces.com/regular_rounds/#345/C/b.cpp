#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
#include <fstream>
using namespace std;

#define ll long long
#define type int

type min(type a, type b)
{
	return (a>b)?b:a;
}

type max(type a, type b)
{
	return (a>b)?a:b;
}

void swap(type &a, type &b)
{
	type t=a;
	a=b;
	b=t;
	return;
}

type gcd (type a, type b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}

type lcm(type a, type b)
{
	return (a/gcd(a,b))*b;
}

type abs(type a)
{
	return (a>0)?a:-a;
}

void files()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main()
{
    freopen("a.txt", "r", stdin);
	int n;
	scanf("%d",&n);
	vector<int>a(n,0);
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	int res=0,temp=0,te=1;
	while(a.size()>0)
	{
		temp=a[0];
		te=1;
		a.erase(a.begin());
		for(int i=0;i<a.size();i++)
		{
			if(a[i]>temp)
			{
				temp=a[i];
				a.erase(a.begin()+i);
				i--;
				te++;
			}
		}
		res+=te-1;
	}
	printf("%d",res);
}
