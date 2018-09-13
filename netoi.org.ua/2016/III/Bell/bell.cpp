#include <iostream>
#include <cmath>




using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    double m, r, ro;

    cin >> m >> r >> ro;

    double h = cbrt(3*m/(ro*acos(-1)));

    cout.precision(20);
    if(h<=r)
        cout << (fixed) << h;
    else
        cout << -1;

	return 0;
}
