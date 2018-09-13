#include <iostream>

using namespace std;

int answers[1000000];
int main(){
	ios::sync_with_stdio(false);
	int n;
	answers[0] = 2;
	answers[1] = 2;
	cin >> n;
	for(int i = 2; i<=n; i++)
	{
		answers[i] = 2*(answers[i-1]+answers[i-2])%100000;
	}
	cout << answers[n]-!(n&1);
	return 0;
}