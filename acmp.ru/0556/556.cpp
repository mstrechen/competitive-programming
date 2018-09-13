#include <iostream>

using namespace std;
double lastTrue, lastFalse,nextTrue=1,nextFalse=0;
int main(){
	ios::sync_with_stdio(false);
	int n;
	double p;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> p;
		lastFalse = nextFalse;
		lastTrue = nextTrue;
		nextTrue = lastTrue*p+(1-p)*lastFalse;
		nextFalse = lastTrue*(1-p) + lastFalse*p;
	}
	cout << nextTrue;
	
	return 0;
}