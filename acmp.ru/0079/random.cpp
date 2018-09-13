#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	ofstream cout("input.txt");
	ios::sync_with_stdio(false);
	for(int i = 0; i<10000000; i++)
	{
		cout << rand()%10;
	}
	cout << ' ';
	for(int i = 0; i<10000000; i++)
	{
		cout << rand()%10;
	}
	return 0;
}