#include<iostream>
#include<string>

using namespace std;

string s[1000];

int main()
{
    ios::sync_with_stdio(false);
	int n;
	cin >> n;
	bool flag = 0;

	for(int i = 0; i<n; i++)
	{
		cin >> s[i];
		if(!flag)
		{
			if(s[i][0]=='O'&&s[i][1]=='O')
			{
				flag = 1;
				s[i][0] = '+';
				s[i][1] = '+';
			}
			else
			if(s[i][3]=='O'&&s[i][4]=='O')
			{
				flag = 1;
				s[i][3] = '+';
				s[i][4] = '+';
			}

		}
	}
	if(flag)
	{
		cout << "YES\n";
		for(int i = 0; i<n; i++)
		{
			cout << s[i] << '\n';
		}
	}
	else
	{
		cout << "NO";
	}
    return 0;
}
