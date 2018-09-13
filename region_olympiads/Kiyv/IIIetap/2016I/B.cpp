#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n = 10000;
	int a = 1000000;
	int b = 29300;
	for(int i = 1; i<n; i++)
		for(int j = 1; j<n; j++)
		{
			b = b*i%(a-j);
		}
	return 0;
}