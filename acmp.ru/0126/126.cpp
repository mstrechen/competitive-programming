#include <iostream>

using namespace std;

int matrixOfConnected[100][100];
int main(){
	ios::sync_with_stdio(false);
	int n,answer = 100500;
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
		for(int j = i+1; j<n; j++)
		{
			for(int k = j+1; k<n; k++)
			{
				answer = min(answer, 
							matrixOfConnected[i][j]+
							matrixOfConnected[j][k]+
							matrixOfConnected[k][i]);
			}
		}
	}
	cout << answer;
	return 0;
}