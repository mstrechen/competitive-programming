#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	ofstream cout("input.txt");
	for(int i = 0; i<200000; i++)
	{
		for(int j = 0; j<10; j++)
		{
			cout << (char)('a'+rand()%26);
		}
		cout << '\n';
	}
	return 0;
}