#include <iostream>

using namespace std;

int gcd(int a,int b){
	int tmp;
	while(b!=0){
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	cout << gcd(n,m);
	return 0;
}