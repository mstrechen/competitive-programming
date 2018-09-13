#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string e = "2.7182818284590452353602875;
	int n;
	cin >> n;
	cout.precision(n);
	cout << (fixed) << e;
	return 0;
}