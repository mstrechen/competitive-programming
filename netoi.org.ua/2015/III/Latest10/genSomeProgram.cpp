#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	ofstream cout("ouputProgram.cpp");
	cout << '"';
	for(int i =0; i<500000;i++)
	{
		cout << i%10;
	}
	cout << '"';
	return 0;
}