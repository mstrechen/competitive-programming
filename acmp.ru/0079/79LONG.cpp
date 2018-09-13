#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
using namespace std;
int powEnds[10][5] = {
		{1,0,0,0,0},
		{1,1,0,0,0},
		{4,2,4,8,6},
		{4,3,9,7,1},
		{2,4,6,0,0},
		{1,5,0,0,0},
		{1,6,0,0,0},
		{4,7,9,3,1},
		{4,8,4,2,6},
		{2,9,1,0,0}};

int main(){
	ifstream cin("input.txt");
	ios::sync_with_stdio(false);
	double be = clock();
	string b,tmpString;
	int aInt,modular;
	cin >> b;
	aInt = (int)(b[b.length()-1]) - 48;
	cin >> b;
	
	int divInt =  powEnds[aInt][0];
	int modEnd = 0;
	for(int i = 0; i<b.length();i++)
	{
		modEnd = (modEnd*10+(int)b[i]-48)%divInt;
	}
	if(modEnd == 0)
	{
		modEnd = divInt;
	}
	cout << powEnds[aInt][modEnd];
	double en = clock();
	//cout << "\n TIME:" << (en-be)/CLOCKS_PER_SEC;
	return 0;
}