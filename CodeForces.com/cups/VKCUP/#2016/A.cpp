#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	double d,h,v, e;
	cin >> d >> h >> v >> e;
	h/=e;
	e*=3.14159265*d*d/4;
	if(e+1e-8>v)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n";
		cout.precision(20);
		cout << e*h/(v-e);
	}
	return 0;
}