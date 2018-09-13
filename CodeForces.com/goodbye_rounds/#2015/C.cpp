#include <iostream>
#include <fstream>

using namespace std;
int field[502][502];
int summV[502][502],summH[502][502];
int answers[1000000];
int main(){
	//ifstream cin("input.txt");
	ios::sync_with_stdio(false);
	char tmp;
	int n, m,k,x1,x2,y1,y2;
	cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			cin >> tmp;
			field[i][j] = (tmp=='.');
		}
	}
	for(int i = 0; i<=n; i++)
	{
		field[i][m+1] = 0;
	}
	
	for(int i = 0; i<=m; i++)
	{
		field[n+1][i] = 0;
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<m; j++)
		{
			summH[i][j] = field[i][j]*field[i][j+1]; 
		}
		summH[i][m] = 0;
		summH[i][0] = 0;
	}
	for(int i = 1; i<=m; i++)
	{
		for(int j = 1; j<n; j++)
		{
			summV[j][i] = field[j][i]*field[j+1][i];
		}
		summV[n][i] = 0;
		summV[0][i] = 0;
	}	
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			summH[i][j]+=summH[i][j-1];
		}
	}
	for(int i = 2; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			summH[i][j]+=summH[i-1][j];
		}
	}
	
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			summV[i][j]+=summV[i][j-1];
		}
	}
	for(int i = 2; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			summV[i][j]+=summV[i-1][j];
		}
	}
	
	int summ;
	cin >> k;
	for(int i = 1; i<=k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		summ = summH[x2][y2-1];
		summ-= summH[x1-1][y2-1];
		summ-= summH[x2][y1-1];
		summ+= summH[x1-1][y1-1];
		
		summ+= summV[x2-1][y2];
		summ-= summV[x1-1][y2];
		summ-= summV[x2-1][y1-1];
		summ+= summV[x1-1][y1-1];
		answers[i] = summ;
		
	}
	for(int i = 1; i<=k; i++)
	{
		cout << answers[i] <<'\n';
	}
	return 0;
}