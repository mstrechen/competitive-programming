#include <iostream>
#include <cmath> 
using namespace std;

double wow(double x, double y,  double x1,  double y1)
{
	return ( (x-x1)*(x-x1)+(y-y1)*(y-y1));
}
double abbs(double x)
{
	if(x>0) return x; else return -x;
}
double epsilon = 1E-7;

double binarySearch(double xP, double yP, double x1, double y1, double x2, double y2)
{
	int i = 0;
	while(i<100)
	{
		i++;
		if(wow(xP,yP,x1+(x2-x1)/3,y1+(y2-y1)/3)<wow(xP,yP,x1+((x2-x1)/3)*2,y1+((y2-y1)/3)*2))
		{
			x2 = y1+((x2-x1)/3)*2;
			y2 = y1+((y2-y1)/3)*2;
		}
		else
		{
			x1+=(x2-x1)/3;
			y1+=(y2-y1)/3;
		}
	}
	return(wow(x1,y1,xP,yP));
}
double xS[2000000], yS[2000000];
int main(){
	ios::sync_with_stdio(false);
	double x,y, yTmp, xTmp, xOld, yOld, xF, yF,tmpRange, maxRange, minRange;
	int n;
	cin >> n;
	cin >> x >> y;
	cin >> xS[0] >> yS[0];
	maxRange = wow(x,y,xS[0],yS[0]);
	minRange = maxRange;
	for(int i = 1; i<n; i++)
	{
		cin >> xS[i] >> yS[i];
		tmpRange = wow(x,y,xS[i],yS[i]);
		if(tmpRange> maxRange)
		{
			maxRange = tmpRange;
		}
	}
	for(int i = 0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			tmpRange = binarySearch(x,y,xS[i],yS[i],xS[j],yS[j]);
			if(tmpRange<minRange)
			{
				minRange = tmpRange;
			}
		}
	}
	cout.precision(100);
	cout << (maxRange-minRange)*3.14159265359;
	return 0;
}