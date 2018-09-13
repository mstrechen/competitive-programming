#include <iostream>
#include <bitset>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

pair <int, int> maxway[3000][3000];

bool compare(pair<int,int> a, pair<int,int> b)
{
	if( a.first > b.first)
	{
		return 1;
	}
	else
		return 0;
}

int way[3000][3000];

bool used[3000];
int main(){
	ios::sync_with_stdio(false);
	int n,m,tmp1,tmp2;
	int currMaxWay = 0;
	pair<pair<int,int>, pair<int, int>> _way= {{0,0},{0,0}};
	
	cin >> n >> m;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			way[i][j] = 0xFFFF;
	for(int i = 0; i<m; i++)
	{
		cin>> tmp1 >> tmp2;
		way[tmp1-1][tmp2-1] = 1;
	}
	for(int i = 0; i<n; i++)
		way[i][i] = 0;
	
	for(int k = 0; k<n; k++)
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
				way[i][j] = min(way[i][k]+way[k][j],way[i][j]);
	
	for(int i = 0; i<n; i++)
	{	
		for(int j = 0; j<n; j++)
		{
			if(way[i][j] == 0xFFFF)
				way[i][j] = 0;
			maxway[i][j] = {way[i][j], j};
				
		}
		sort(maxway[i], maxway[i]+n, compare);
		
	}
	
	for(int i = 0; i<n; i++)
	{
		for(int i1 = 0; i1<4&&maxway[i][i1].first; i1++)
		{
			int j = maxway[i][i1].second;			
			for(int j1 = 0; j1<4&&maxway[j][j1].first; j1++)
			{
				int k = maxway[j][j1].second;							
				for(int k1 = 0; k1<4&&maxway[k][k1].first; k1++)
				{
					int l = maxway[k][k1].second;
					if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l&&currMaxWay<way[i][j]+way[j][k]+way[k][l])
					{
						currMaxWay=way[i][j]+way[j][k]+way[k][l];
						_way = {{i,j},{k,l}};
					}
						
				}
			}
		}
	}
	cout << _way.first.first+1 << ' '<<_way.first.second+1 <<  ' '<<_way.second.first+1 <<  ' '<<_way.second.second+1;
	return 0;
}