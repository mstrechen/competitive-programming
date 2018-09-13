#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double  a1, b1, c1,
            a2, b2, c2,
            a3, b3, c3;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    cin >> a3 >> b3 >> c3;

    double x1 = -(c1*b2 - c2*b1)/(a1*b2 - a2*b1),
           y1 = -(a1*c2 - a2*c1)/(a1*b2 - a2*b1);
    double x2 = -(c3*b2 - c2*b3)/(a3*b2 - a2*b3),
           y2 = -(a3*c2 - a2*c3)/(a3*b2 - a2*b3);
    double x3 = -(c1*b3 - c3*b1)/(a1*b3 - a3*b1),
           y3 = -(a1*c3 - a3*c1)/(a1*b3 - a3*b1);

    cout << abs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1))/2;

    return 0;
}
