#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	int answer=1;
	string stringToParse;
	getline(cin,stringToParse);
	int i = stringToParse.length()-stringToParse.find(' ')-1;
	stringToParse = stringToParse.substr(0,stringToParse.find(' ')); 
	n = atoi( stringToParse.c_str() );
	
	for(int j = n; j>1; j-=i)
	{
		answer*=j;
	}
	cout << answer;
	return 0;
}