#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPSILON = 1E-6;
struct line{
	double a,b,c,x,y,length;
} lines[10];

struct point{
	double x,y;
} points[10];
point pointOfBisec;
line bisec[2];

int main(){
	ios::sync_with_stdio(false);
	int n;
	double radius,p=0,area=0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> points[i].x >> points[i].y;
	}
	points[n] = points[0];
	for(int i=0; i<n; i++)
	{
		lines[i].a=points[i+1].x-points[i].x;
		lines[i].b=points[i].y-points[i+1].y;
		lines[i].c = -(lines[i].a*points[i].x+lines[i].b*points[i].y);
		lines[i].length = sqrt(lines[i].a*lines[i].a+lines[i].b*lines[i].b);
		lines[i].x = lines[i].a/lines[i].length;
		lines[i].y = -lines[i].b/lines[i].length;
	}
	for(int i =0; i<n; i++)
	{
		area+=(points[i].x+points[i+1].x)*(points[i].y - points[i+1].y);
		p+=sqrt((points[i].x-points[i+1].x)*(points[i].x-points[i+1].x)+(points[i].y-points[i+1].y)*(points[i].y-points[i+1].y));
	}
	area = abs(area);
	radius = area/p;
	
	cout << radius;
	return 0;
}