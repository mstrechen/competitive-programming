#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	string s;
	
	int n;
	cin >> n;
	cin >> s;
	
	int i = 0;
	int ans = 0;
	while(i<n&&s[i]=='<')
	{
		i++;
		ans++;
	}
	i = n-1;
	while(i>=0&&s[i]=='>')
	{
		i--;
		ans++;
	}
	cout << ans;
	
	return 0;
}