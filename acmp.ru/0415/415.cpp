#include <iostream>
#include <string>
using namespace std;

char toLowerCase(char c)
{
	if(c>='A'&&c<='Z')
	{
		return c-('A'-'a'); 
	}
	return c;
}
char toUpperCase(char c)
{
	if(c>='a'&&c<='z')
	{
		return c-('a'-'A'); 
	}
	return c;
}
int main(){
	ios::sync_with_stdio(false);
	string name1, name2;
	cin >> name1 >> name2;
	name1[0] = toLowerCase(name1[0]);
	name2[0] = toLowerCase(name2[0]);
	for(int i = 0; i<name1.length());
	return 0;
}