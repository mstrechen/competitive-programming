#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

__int8 a[1002][1002];
 int vert[1002][1002],hor[1002][1002];
int main(){
	ifstream cin("input.txt");
	ios::sync_with_stdio(false);
	char c;
	int n,m,summary=0,maxS=0;
	cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			cin >>  c;
			a[i][j] = (c=='1');
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			hor[i][j] = (hor[i][j-1]+1)*(a[i][j]==1);
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			vert[i][j] = (vert[i-1][j]+1)*(a[i][j]==1);
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			int minH = vert[i][j];
			for(int k = 0; k<hor[i][j]; k++)
			{
				minH = min(minH, vert[i][j-k]);
				maxS = max(maxS, (k+1)*minH);
			}
		}
	}
	
	cout << maxS;
	
	return 0;
}