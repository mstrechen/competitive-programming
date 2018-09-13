#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string s,ofword, what;
	getline(cin, s);
	int n;
	istringstream s1(s);
	s1 >> n;
	s1 >> ofword;
	s1 >> what;
	if(what == "month")
	{
		if(n==31)
		{
			cout << 7;
		}
		if(n==30)
		{
			cout << 11;
		}
		if(n<30)
		{
			cout << 12;
		}
	}
	else
	{
		if(n==5||n==6)
		{
			cout << 53;
		}
		else
		{
			cout << 52;
		}
	}
	return 0;
}