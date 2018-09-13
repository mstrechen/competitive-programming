#include <iostream>

using namespace std;

bool check(int a,int b, int c)
{
	return (a<=c&&b<=c)||(a>=c&&b>=c);
}
int main(){
	ios::sync_with_stdio(false);
	int x1,x2,x3,y1,y2,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if((x1==x2&&x2==x3)||(y1==y2&&y2==y3))
	{
		cout << 1;
		return 0;
	}
	if((x1==x2&&check(y1,y2,y3))||(x3==x2&&check(y3,y2,y1))||(x1==x3&&check(y1,y3,y2))||(y1==y2&&check(x1,x2,x3))||(y3==y2&&check(x3,x2,x1))||(y1==y3&&check(x1,x3,x2)))
	{
		
		cout << 2;
		return 0;
	}
	else
	{
		cout << 3;
	}
	return 0;
}