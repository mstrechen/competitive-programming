#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	int currentCountOfOpened=0;
	int maxCount = 0;
	char c;
	cin >> n >> m;
	for(int i = 0; i<m; i++)
	{
		cin >> c;
		if(c=='(')
		{
			currentCountOfOpened++;
		}
		else
		{
			currentCountOfOpened--;
		}
		maxCount = max(maxCount, -currentCountOfOpened);
	}
	
	
	return 0;
}