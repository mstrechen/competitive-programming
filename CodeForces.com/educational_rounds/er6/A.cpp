#include <iostream>
using namespace std;

long long abbs(long long a)
{
	if(a>0)
	{
		return a;
	}
	else
	{
		return -a;
	}
}
long long max(long long a,long long b)
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
int main(){
	ios::sync_with_stdio(false);
	long long x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << max(abbs(x1-x2),abbs(y1-y2));
	return 0;
}