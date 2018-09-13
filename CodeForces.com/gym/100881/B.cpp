#include <iostream>
#include <fstream>
using namespace std;

bool isPossible(__int64 a,__int64 b,__int64 w,__int64 h,__int64 n)
{
	return ((w/a)*(h/b)>=n)||((w/b)*(h/a)>=n);
}
int main(){
	ofstream cout("space.out");
	ifstream  cin("space.in");
	ios::sync_with_stdio(false);
	__int64 n,a, b, w,h, i,j;
	cin >> n >> a >> b >> w >> h;
	for(i = 0, j =5e17; i<j-1;)
	{
		if(isPossible(a+i+j, b+i+j, w,h,n))
		{
			i = (i+j)/2;
		}
		else
		{
			j = (i+j)/2;
		}
	}
	if(isPossible(a+((i+j-1)/2 + 1 )*2, b+((i+j-1)/2 + 1 )*2, w,h,n))
	{
		cout << (i+j-1)/2 + 1;
	}
	else
	{
		cout << (i+j)/2;
	}
	return 0;
}