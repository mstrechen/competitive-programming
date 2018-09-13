#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


long long _gcd(long long a, long long b)
{
    if(a&&b)
    {
        return _gcd(b, a%b);
    }
    return a+b;
}
long long  gcd (long long a, long long b, long long & x, long long & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution (long long a, long long b,  long long c, long long & x0, long long & y0, long long & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;

    if(x0<0)
        x0+=(abs(x0)/(b/g))*(b/g);
    if(x0<0)
        x0+=b/g;
    if(x0>b/g)
        x0-=((x0)/(b/g))*(b/g);

	return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    int k;
    cin >> n >> m >> k;

    long long x,y;

    long long ggcd = n*m/_gcd(n,m);

    vector<long long> solutions;
    for(int i = 0; i<k; i++)
    {
        cin >> x >> y;
        long long x1 = n+abs(n-x);
        long long y1 = m+abs(m-y);
        solutions.clear();
        long long A,B;
        long long tmp;
        if(find_any_solution(-2*n, 2*m, x-y, A, B, tmp))
        {
            tmp = x+2*n*A;
            tmp%=2*ggcd;
            tmp = min(tmp, 2*ggcd-tmp);
            solutions.push_back(tmp);

        }
        if(find_any_solution(-2*n, 2*m, x1-y, A, B, tmp))
        {
            tmp = x1+2*n*A;
            tmp%=2*ggcd;
            tmp = min(tmp, 2*ggcd-tmp);
            solutions.push_back(tmp);
        }
        if(find_any_solution(-2*n, 2*m, x-y1, A, B, tmp))
        {
            tmp = x+2*n*A;
            tmp%=2*ggcd;
            tmp = min(tmp, 2*ggcd-tmp);
            solutions.push_back(tmp);
        }
        if(find_any_solution(-2*n, 2*m, x1-y1, A, B, tmp))
        {
            tmp = x1+2*n*A;
            tmp%=2*ggcd;
            tmp = min(tmp, 2*ggcd-tmp);
            solutions.push_back(tmp);
        }
        sort(solutions.begin(),solutions.end());
        if(solutions.size())
            cout << solutions[0];
        else
            cout << -1;
        cout << '\n';

    }

    return 0;
}
