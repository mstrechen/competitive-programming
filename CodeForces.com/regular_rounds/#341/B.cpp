#include <iostream>

using namespace std;
const int MAGICCONST = 10000;
int diag1[30000], diag2[30000];
int main(){
	ios::sync_with_stdio(false);
	int n, x,y,minDiag1,maxDiag1, minDiag2,maxDiag2;
	long long answer = 0;
	cin >> n;
	cin >> x >> y;
	diag1[x+y]++;
	diag2[x-y+MAGICCONST]++;
	minDiag1 = maxDiag1 = x+y;
	minDiag2 = maxDiag2 = x-y+MAGICCONST;
	for(int i = 1; i<n; i++)
	{
		cin >> x >> y;
		diag1[x+y]++;
		diag2[x-y+MAGICCONST]++;
		minDiag1 = min(minDiag1,x+y);
		maxDiag1 = max(maxDiag1,x+y);
		minDiag2 = min(minDiag2,x-y+MAGICCONST);
		maxDiag2 = max(maxDiag2,x-y+MAGICCONST);
	}
	
	for(int i = minDiag1; i<=maxDiag1; i++)
	{
		answer+=diag1[i]*(diag1[i]-1)/2;	
	}
	for(int i = minDiag2; i<=maxDiag2; i++)
	{
		answer+=diag2[i]*(diag2[i]-1)/2;
	}
	cout << answer;
	return 0;
}