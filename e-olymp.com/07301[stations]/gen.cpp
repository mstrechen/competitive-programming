#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	ofstream cout("input.txt");
	cout << 1000 << ' ' << 1000 << '\n';
	for(int i = 1; i<1000; i++)
	{
		for(int j = 0; j<i; j++)
		{
			cout << 10000 <<' ';
		}
		cout << '\n';
	}
	
	return 0;
}