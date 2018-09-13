#include <iostream>
#include <string>

using namespace std;

char answer(char c)
{
	if(c=='g')
	{
		return 'g';
	}
	if(c=='r')
	{
		return 'b';
	}
	if(c=='b')
	{
		return 'r';
	}
}

char c[20];
string s;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> s;
		c[i] = s[0];
	}
	for(int i = 0; i<n; i++)
	{
		cout << answer(c[i]) <<' ';
	}
	
	return 0;
}