#include <iostream>
#include <bitset>


using namespace std;

int mask = 0;
int maxAns = -1;
int n;
char _st[32], _ans[32]; 
char * st = _st;
char * ans = _ans;

int a[30][30];

void getAns(int n)
{
	int curans = 0;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			curans+=(a[i][j] && (st[i]==st[j]) );
	if(curans>maxAns)
	{
		maxAns = curans;
		swap(st, ans);
	}
}



int main(){
	ios::sync_with_stdio(false);
	
	int k, m;
	cin >> n >> k >> m;
	int x,y;
	for(int i = 0; i<m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	
	int maxn = 1 << n;
	for(int i  = 0; i<maxn	; i++)
	{
		if(__builtin_popcount(i)==k)
		{
			for(int j = 0; j<n; j++)
			{
				st[j] = (i>>j)&1;
			}
			getAns(n);
		}
	}

	
	for(int i = 0;i<n; i++)
		if(ans[i]==1)
			cout << i+1 << ' '; 
	
	
	return 0;
}