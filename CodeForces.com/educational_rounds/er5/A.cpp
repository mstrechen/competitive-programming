#include <iostream>
#include <string>

using namespace std;

string a,b;
int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b;
	int i,j;
	for(i = 0; (i<a.length())&&(a[i]=='0');i++){}
	for(j = 0; (j<b.length())&&(b[j]=='0');j++){}
	
	if(a.length()-i!=b.length()-j)
	{
		if(a.length()-i>b.length()-j)
		{
			cout << '>';
		}
		else
		{
			cout << '<'; 
		}
	}
	else
	{
		for(;i<a.length();)
		{
			if(a[i]!=b[j])
			{
				if(a[i]>b[j])
				{
					cout << '>';
				}
				else
				{
					cout << '<';
				}
				return 0;
			}
			i++; j++;
		}
		
		cout << '=';
	}
	return 0;
}