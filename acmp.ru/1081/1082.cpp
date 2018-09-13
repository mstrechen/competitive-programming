#include <stdio.h>

using namespace std;

long long a[1005][1005];

int main(){
	
	int n, m,k;
	
	scanf("%d%d%d",&n, &m , &k);
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++)
			scanf("%I64d",&a[i][j]);
		
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++)
			a[i][j]+=a[i][j-1] + a[i-1][j] - a[i-1][j-1];
		
	int x1,y1,x2,y2;
	for(int i = 0; i<k; i++)
	{
		scanf("%d%d%d%d",&x1, &y1, &x2,&y2);
		printf("%I64d\n", a[x2][y2] + a[x1-1][y1-1] - a[x1-1][y2] - a[x2][y1-1]);
	}
	
	return 0;
}