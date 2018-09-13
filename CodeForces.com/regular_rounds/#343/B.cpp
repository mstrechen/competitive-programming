#include <iostream>
#include <algorithm>
using namespace std;

int days[368][2];

int main(){
	ios::sync_with_stdio(false);
	int n, be,en;
	char c;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> c >> be >> en;
		if(c=='M')
		{
			days[be][0]++;
			days[en+1][0]--;
		}
		else
		{
			days[be][1]++;
			days[en+1][1]--;
		}
	}
	int currM=0, currF=0, maxC=0;
	for(int i = 1; i<=366; i++)
	{
		currM+=days[i][0];
		currF+=days[i][1];
		maxC = max(min(currF,currM),maxC);
	}
	cout << maxC*2;
	return 0;
}