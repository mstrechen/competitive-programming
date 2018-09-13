#include <iostream>
#include <string>

using namespace std;

string s;
int main(){
	ios::sync_with_stdio(false);
	
	cin >> s;
	
	for(int i = 1; i<s.length()-1; i++)
	{
		if(s[i-1]==s[i])
		{
				 if(s[i-1]!='a'&&s[i+1]!='a')s[i] = 'a';
			else if(s[i-1]!='b'&&s[i+1]!='b')s[i] = 'b';
			else s[i] = 'c';
		}
	}
	if(s[s.length()-1]==s[s.length()-2])
	{
		if(s[s.length()-1]=='a') s[s.length()-1] = 'b';
		else s[s.length()-1] = 'a';
	}
	cout << s;
	return 0;
}