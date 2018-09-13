#include<iostream>
#include<cmath>

using namespace std;

const double PI = acos(-1);
const double len = 15650;
const double deltaT = 0.005;
const double beginV = 800;
const double g = 9.8;

double getS(double k, double angle)
{
    angle/=180;
    angle*=PI;
    double v = beginV;
    double vx,vy;
    double s = 0;
	double sY = 0;
    do
    {
        double ax = -v*v*k*cos(angle);
		double ay = -g-k*v*v*sin(angle);
		s+=v*cos(angle)*deltaT;
		sY+=v*sin(angle)*deltaT;
		vx = v*cos(angle) + ax*deltaT;
		vy = v*sin(angle) + ay*deltaT;
		v = sqrt(vx*vx+vy*vy);
		angle = atan(vy/vx);
	}
	while(sY>0);
    return s;
}


int main()
{
    ios::sync_with_stdio(false);

    double angle;
    
	cout << "";
	
	cin >> angle;
	

    double l = 0, r = 0.03;
	 
    while(l<r-0.0000000001)
    {
		
        double mid = (l+r)/2;
		if(getS(mid,45)>len)
            l = mid;
        else
            r = mid;
    }
    cout.precision(0);
    cout << (fixed) << getS(l, angle);

    return 0;
}
