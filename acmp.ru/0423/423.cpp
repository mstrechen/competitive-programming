#include <iostream>
#include <string>
using namespace std;
string justAnotherGlobalString;
long long haaaaash[200] = {};
long long numOfVariants(int i)
{
	if(haaaaash[i]>0)
	{
		return haaaaash[i];
	}
	if(i>=justAnotherGlobalString.length()-1)
	{
		haaaaash[i]=1;
	}
	else
	{
		char a = justAnotherGlobalString[i];
		char b = justAnotherGlobalString[i+1];
		if(a=='0'||a>'3'||(a=='3'&&b>'3'))
		{
			haaaaash[i]=numOfVariants(i+1);
		}
		else
		{
			haaaaash[i]=numOfVariants(i+1)+numOfVariants(i+2);
		}
	}
	return haaaaash[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin >> justAnotherGlobalString;
	cout << numOfVariants(0);
	return 0;
}