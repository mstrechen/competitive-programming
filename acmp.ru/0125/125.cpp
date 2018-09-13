#include <iostream>

using namespace std;

int matrixOfConnected[100][100];
int colors[100];
int main(){
	ios::sync_with_stdio(false);
	int n,answer = 0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cin >> matrixOfConnected[i][j];
		}
	}
	for(int i = 0; i<n; i++)
	{
		cin >> colors[i];
	}
	
	for(int i = 0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			if(matrixOfConnected[i][j]&&colors[i]!=colors[j])
			{
				answer++;
			}
		}
	}
	cout << answer;
	return 0;
}