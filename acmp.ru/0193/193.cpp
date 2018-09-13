#include <iostream>
#include <cmath>
using namespace std;

int minX[256],maxX[256],minY[256],maxY[256];
int was[256];
int main(){
	for(int i = 0; i<256; i++)
	{
		minX[i] = 200;
		minY[i] = 200;
	}
	ios::sync_with_stdio(false);
	int n, k, m,tmp,minWas=1;
	cin >> n >> m >> k;
	for(int i = n; i>0; i--)
	{
		for(int j = 1; j<=m; j++)
		{
			cin >> tmp;
			was[tmp]=1;
			minX[tmp] = min(minX[tmp],j);
			minY[tmp] = min(minY[tmp],i);
			maxX[tmp] = max(maxX[tmp],j);
			maxY[tmp] = max(maxY[tmp],i);
		}
	}
	for(int i = 1; i<=k; i++)
	{
		if(was[i]==1)
		{
			minWas=i;
			break;
		}
	}
	for(int i = 1; i<=k; i++)
	{
		if(was[i]==1)
		{
			cout << minX[i]-1 << ' '<< minY[i]-1 << ' '<< maxX[i] << ' '<< maxY[i] << '\n';
		}
		else
		{
			cout << minX[minWas]-1 << ' '<< minY[minWas]-1 << ' '<< maxX[minWas] << ' '<< maxY[minWas] << '\n';
		}
	}
	return 0;
}