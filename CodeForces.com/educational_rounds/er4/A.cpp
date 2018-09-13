#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,p,q;
	string s;
	cin >> n >> p >> q;
	cin >> s;
	for(int i = 0; i*p<=n;i++)
	{
		if((n-i*p)%q==0)
		{
			cout << i+(n-i*p)/q <<'\n';
			for(int j = 0; j<i; j++)
			{
				for(int k = 0; k<p; k++)
				{
					cout << s[j*p+k];
				}
				cout << '\n';
			}
			for(int j = 0; j*q<(n-i*p); j++)
			{
				for(int k = 0; k<q; k++)
				{
					cout << s[i*p+j*q+k];
				}
				cout << '\n';
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}