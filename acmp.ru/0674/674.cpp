#include <iostream>
//#include <ctime>
using namespace std;
int wat=0;
long long numOfVars(int n)
{
	if(n < 3)
	{
		return 0;
	}
	if( n == 3)
	{
		return 1;
	}
	return numOfVars(n/2)*2;
	
		
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	//double be = clock();
	cout << numOfVars(n);
	//double en = clock();
	//cout << "TIME" << (en-be)/CLOCKS_PER_SEC;
	//cout << "wat:" << wat;
	return 0; 
}