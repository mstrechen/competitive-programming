#include<iostream>
#include<cmath>

using namespace std;

const double eps = 1e-6;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    double X, Y, R, x1,y1,x2,y2;
    cin >> X >> Y >> R;
    cin >> x1 >> y1 >> x2 >> y2;

    if(abs(x1-x2) < eps)
    {
        swap(X,Y);
        swap(x1,y1);
        swap(x2,y2);
    }

    if(x1>x2)
        swap(x1,x2);

    if(abs(y1 - Y) >= R)
    {
        cout << 0;
        return 0;
    }

    double delta = sqrt(R*R - (y1-Y)*(y1-Y));

    x1 = max(x1, X-delta);
    x2 = min(x2, X+delta);

    cout << max(x2-x1, double(0));

    return 0;
}
