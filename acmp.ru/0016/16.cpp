#include <iostream>

using namespace std;

long long variants(int n, int maxLevel){
	long long summ = 0;
	if(n<0){return 0;}
	else if(n<2){return 1;}
	else for(int i = 2; i<=maxLevel; i++) summ+=variants(n-i, i-1);
	return summ;
}

int main(){
	ios::sync_with_stdio(false);
	long long n;
	cin >> n;
	cout << variants(n,n);
	return 0;
}