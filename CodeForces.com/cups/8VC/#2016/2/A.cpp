#include <iostream>

using namespace std;

int tAlts[20][20];

int main(){
	ios::sync_with_stdio(false);
	int a,b, n,k,tmp1,tmp2;
	long long counter = 0;
	cin >> a >> b >> n >> k;
	for(int i = 0; i<n; i++)
	{
		cin >> tmp1 >> tmp2;
		tAlts[tmp1][tmp2]++;
	}
	for(int i = 1; i<=a; i++)
	{
		for(int j = 1; j<=b; j++)
		{
			tAlts[i][j]+= tAlts[i-1][j]+tAlts[i][j-1]-tAlts[i-1][j-1];
		}
	}
	for(int i1 = 0; i1<a; i1++)
	{
		for(int j1 = 0; j1<b; j1++)
		{
			for(int i2 = i1+1; i2<=a; i2++)
			{
				for(int j2 = j1+1; j2<=b; j2++)
				{
					if(tAlts[i2][j2]+tAlts[i1][j1]-tAlts[i1][j2]-tAlts[i2][j1]>=k)
					{
						counter++;
					}
				}
			}
		}
	}
	cout << counter;
	return 0;
}