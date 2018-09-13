#include <iostream>
#include <string>
using namespace std;

int a[300][2];
int v(char c)
{
	if(c=='U') return 1;
	if(c=='D') return -1;
	return 0;
}
int h(char c)
{
	if(c=='L') return -1;
	if(c=='R') return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	string s;
	int n;
	cin >> n;
	cin >> s;
	int k = 0;
	a[1][0] = v(s[0]);
	a[1][1] = h(s[0]);
	for(int i = 1; i<n; i++)
	{
		a[i+1][0] = v(s[i]);
		a[i+1][1] = h(s[i]);
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = i; j<=n; j++)
		{
			if((a[j][0]-a[i-1][0]==a[n][0])&&(a[j][1]-a[i-1][1]==a[n][1]))
			{
				k++;
			}
		}
	}
	cout << k-1;
	return 0;
}