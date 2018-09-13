#include <iostream>
#include <cstring>
using namespace std;
struct YAS{
	int x,y;
	
} queue[1100000];

int num[1002][1002],clr[1002][1002];
char field[1002][1002];
int main(){
	memset(field, '*',sizeof(field));
	ios::sync_with_stdio(false);
	int be,en;
	int n,m;
	int currColor=1;
	cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			cin >> field[i][j];
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			if(field[i][j]=='.'&&clr[i][j]==0)
			{
				be = 0;
				en = 1;
				queue[be].x=i;
				queue[be].y=j;
				while(en>be)
				{
					clr[queue[be].x][queue[be].y] = currColor;
					if(	)
				}
				
				currColor++;
			}
		}
	}
	return 0;
}