#include <iostream>
using namespace std;
long long abs(long long a){
	if(a>=0)
	{
		return a;
	}  
	else
	{
		return -a;	
	}
}
long long getDoubleSizeOfTrapeze(pair<long long, long long> a, pair<long long, long long> b)
{
	return (a.first + b.first)*(b.second - a.second);
}
long long gcd(int a,int b )
{
	int tmp;
	if(a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while(b>0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
long long getCountOfPoints(pair<long long, long long> a, pair<long long, long long> b)
{
	return gcd(abs(a.first-b.first),abs(a.second-b.second));
}

int main(){
	ios::sync_with_stdio(false);
	int n,tmpX,tmpY;
	long long summ = 0,countOfPoints = 0;
	pair<long long, long long> firstPoint, nextPoint, prevPoint;
	
	cin >> n;
	cin >> tmpX >> tmpY;
	firstPoint = make_pair(tmpX,tmpY);
	nextPoint = firstPoint;
	for(int i = 1; i<n; i++)
	{
		prevPoint = nextPoint;
		cin >> tmpX >> tmpY;
		nextPoint = make_pair(tmpX,tmpY);
		summ+=getDoubleSizeOfTrapeze(prevPoint,nextPoint);
		countOfPoints+=getCountOfPoints(prevPoint,nextPoint);
	}
	summ+=getDoubleSizeOfTrapeze(nextPoint,firstPoint);
	countOfPoints+=getCountOfPoints(nextPoint,firstPoint);
	summ = abs(summ);
	cout << summ/2 -  countOfPoints/2 + 1;
return 0;
}