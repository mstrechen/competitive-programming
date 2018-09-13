#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	ofstream cout("test.txt");
	for(int i = 0; i<10000; i++)
	{
		cout << i << ' ';
	}
	return 0;
}