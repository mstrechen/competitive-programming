#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cout << 200000 << '\n';
	for(int i = 0; i<200000; i++)
	{
		cout << 0 << ' ' << i << '\n';
	}
	return 0;
}