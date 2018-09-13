#include <iostream>
#include <string>

using namespace std;

string s,s1;
int a[1000000], b[1000000];
int main(){
	ios::sync_with_stdio(false);
	unsigned long long n;
	cin >> s1;
	s.assign(s1.rbegin(), s1.rend());
	n = s.length();
	for(int i = 0; i<s.length(); i++)
	{
		a[i] = s[i]-'0';
	}
	cin >> s1;
	s.assign(s1.rbegin(), s1.rend());
	for(int i = 0; i<s.length(); i++)
	{
		a[i] -= s[i]-'0';
		if(a[i]<0&&i!=max(n-1, s.length()-1))
		{
			a[i]+=10;
			a[i+1]--;
		}
	}
	for(int i = s.length(); i<n; i++)
	{
		if(a[i]<0&&i!=max(n-1, s.length()-1))
		{
			a[i]+=10;
			a[i+1]--;
		}
	}
	for(int i = max(s.length(),n)-1; i>=0; i--)
	{
		cout << a[i];
	}
	
	return 0;
}