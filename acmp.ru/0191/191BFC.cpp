#include <iostream>
#include <fstream>
using namespace std;

bool isNice(__int64 a)
{
	int last  = 10,current;
	while(a>0)
	{
		current = a%10;
		a/=10;
		if(current>last)
		{
			return false;
		}
		last = current;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	ofstream cout("output.txt");
	int j=0;
	for(__int64 i = 1; j<=2147483; i++)
	{
		if(isNice(i))
		{
			++j;
			cout << j << " : " << i << '\n';
		}
	}
	
	return 0;
}