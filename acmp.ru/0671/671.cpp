#include <iostream>
#include <string>
using namespace std;

__int64 f(int x)
{
	__int64 answer = 1;
	answer <<=x;
	return answer;
}
int main(){
	ios::sync_with_stdio(false);
	__int64 answer=1;
	string s;
	cin >> s;
	for(int i = 0; i<s.length(); i++)
	{
		
	}
	for(int i = 1; i<s.length(); i++)
	{
		answer+=f(i);
	}
	cout << answer;
	return 0;
}