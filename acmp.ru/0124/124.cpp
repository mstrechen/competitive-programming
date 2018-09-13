#include <iostream>

using namespace std;

int countOfConnected[101];

int main(){
	ios::sync_with_stdio(false);
	int n,m,tmp1,tmp2;
	cin >> n >> m;
	for(int i = 0; i<m; i++)
	{
		cin >> tmp1 >> tmp2;
		countOfConnected[tmp1]++;
		countOfConnected[tmp2]++;
	}
	for(int i = 0; i<n; i++)
	{
		cout << countOfConnected[i+1] << ' ';
	}
	return 0;
}