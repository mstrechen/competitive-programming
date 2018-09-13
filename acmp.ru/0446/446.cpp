#include <iostream>

using namespace std;
int g(char c)
{
	int r;
	if(c=='.') r=1;
	else if (c=='R') r=8;
	else if(c=='G') r=4;
	else r=2;
	return r;
}
int main(){
	int n,m,k;
	cin >> n >> m;
	int i,j;
	char t;
	bool b=1;
	int a[100][101];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin >> t;
			a[i][j]=g(t);
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin >> k;
			
			b=b&&((a[i][j]&((k<<1) + 1))>0);
		}
	if(b) cout <<"YES";
	else cout << "NO";
return 0;
}