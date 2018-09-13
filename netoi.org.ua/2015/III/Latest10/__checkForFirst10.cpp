#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
	ofstream cout("resultForFirst10.txt");
	ios::sync_with_stdio(false);
	cout.precision(6);
	for(int i = 0; i<11; i++)
	{
		cout << i << " : " <<fixed << pow((sqrt(3)+1),i) << '\n';
	}
	return 0;
}