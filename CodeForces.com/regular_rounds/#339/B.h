#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	string s,badString='|';
	cin >> n;
	int numOfAllZeros = 0, wasZero=0;
	for(int i = 0; i<n; i++)
	{
		cin >> s;
		if(s.length()=1&&s[0]='0')
		{
			wasZero = 1;
		}
		int count1=0,count0=0,countNot1or0=0;
		for(int j= 0; j<s.length();j++)
		{
			if(s[j]=='0'){ count0++;}
			else
			if(s[j]=='1'){count1++;}
			else{countNot1or0++;}
		}
		if(countNot1or0>0||(count1>1))
		{
			badString = s;
			
		}
		else
		{
			numOfAllZeros+=count0;
		}
	}
	if(wasZero==1)
	{
		cout << 0;
	}
	else
	if(badString=='|')
	{
		cout << 1;
		for(int i = 0; i<numOfAllZeros; i++)
		{
			cout << 0;
		}
	}
	else
	{
		cout << badString;
		
		for(int i = 0; i<numOfAllZeros; i++)
		{
			cout << 0;
		}
	}
	return 0;
}