#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;



double getArea(double h, double m, double bis)
{
	if(m==bis||h==bis||m==h)
		return -1;
	
	double l = 0, r = 100500;
	
	double deltaX = sqrt(m*m-h*h);
	
	while(r-l>0.00000001)
	{
		double mid = (l+r)/2;
		double y = sqrt(h*h+(mid/2-deltaX)*(mid/2-deltaX));
		double z = sqrt(h*h+(mid/2+deltaX)*(mid/2+deltaX));
		double a = mid*y/(y+z);
		double newX = deltaX - mid/2 + a;
		newX = sqrt(newX*newX+h*h);
		if(newX<bis)
			r = mid;
		else
			l = mid;
	}
	return r*h/2;
}


int main(){
	
	double a[3];
	cin >> a[0] >> a[1] >> a[2];
	
	sort(a,a+3);
	
	if(a[0]==a[1]&&a[1]==a[2])
		cout << 0;
	else
	{
		double res1 = getArea(a[0],a[1],a[2]);
		double res2 = getArea(a[0],a[2],a[1]);
		cout.precision(15);
		cout << (fixed);
		if(res1 == -1 && res2 == -1)
			cout << -1;
		else
		if(abs(res1-res2)>0.000001&&min(res1,res2)>0.000001)
			cout << 0;
		else
			cout << max(res1,res2);
	}
	
	return 0;
}