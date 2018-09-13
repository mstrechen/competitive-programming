#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPSILON = 1E-3;
struct line{
	double a,b,c,x,y,length;
} lines[10];

struct point{
	double x,y;
} points[10];
point pointOfBisec;
line bisec[2];

double round1(double x){
	int y = round(x*1000);
	cout << y/1000 << '.' <<y%1000<<' '; 
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> points[i].x >> points[i].y;
	}
	points[n] = points[0];
	for(int i=0; i<n; i++)
	{
		lines[i].b=points[i+1].x-points[i].x;
		lines[i].a=points[i].y-points[i+1].y;
		lines[i].c = -(lines[i].a*points[i].x+lines[i].b*points[i].y);
		lines[i].length = sqrt(lines[i].a*lines[i].a+lines[i].b*lines[i].b);
		lines[i].x = lines[i].a/lines[i].length;
		lines[i].y = -lines[i].b/lines[i].length;
	}
	bisec[0].x = -lines[0].x+lines[1].x;
	bisec[0].y = -lines[0].y+lines[1].y;
	bisec[0].a = bisec[0].y;
	bisec[0].b = -bisec[0].x;
	bisec[0].c = -(bisec[0].a*points[1].x+bisec[0].b*points[1].y);
	
	if((-lines[1].x+lines[2].x+bisec[0].x)==0||(-lines[1].y+lines[2].y+bisec[0].y)==0){
		bisec[1].x = (-lines[1].x+lines[2].x)*2;
		bisec[1].y = (-lines[1].y+lines[2].y)*2;
	}else
	{
		bisec[1].x = (-lines[1].x+lines[2].x);
		bisec[1].y = (-lines[1].y+lines[2].y);
	}
	bisec[1].a = bisec[1].y;
	bisec[1].b = -bisec[1].x;
	bisec[1].c = -(bisec[1].a*points[2].x+bisec[1].b*points[2].y);
	
	pointOfBisec.y = (((bisec[0].c+bisec[1].c)*bisec[0].a)/(bisec[0].a+bisec[1].a)- bisec[0].c)/(bisec[0].b-((bisec[0].b+bisec[1].b)*bisec[0].a)/(bisec[0].a+bisec[1].a));
	
	pointOfBisec.x = -(bisec[0].b*pointOfBisec.y+bisec[0].c)/bisec[0].a;
	
	bool allOk = 1;
	
	double h = abs((pointOfBisec.x*lines[0].a+pointOfBisec.y*lines[0].b+lines[0].c)/sqrt(lines[0].a*lines[0].a + lines[0].b*lines[0].b));
	for(int i = 1; i<n; i++){
		allOk*=(abs(abs((pointOfBisec.x*lines[i].a+pointOfBisec.y*lines[i].b+lines[i].c)/sqrt(lines[i].a*lines[i].a + lines[i].b*lines[i].b))-h)<EPSILON);
		cout << lines[i].a << ' '<< lines[i].b << ' '<< lines[i].c << endl;
		cout << pointOfBisec.x*lines[i].a+pointOfBisec.y*lines[i].b+lines[i].c <<' ' << sqrt(lines[i].a*lines[i].a + lines[i].b*lines[i].b) << endl;
	}
	
		cout << "YES\n";
		round1(pointOfBisec.x);
		round1(pointOfBisec.y);
		round1(h);
	cout << "NO" << allOk;
	return 0;
}