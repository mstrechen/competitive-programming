#include <iostream>
#include <fstream>

using namespace std;

int a[1000][1000];

int main(){
	ios::sync_with_stdio(false);
	ofstream fout("matrix.txt");
	
	int MAXN = 20;
	for(int _i = 1; _i<=MAXN; _i++)
	{
		for(int _j = 1; _j<=MAXN; _j++)
		{
			int g = 0;
			int ans = 0;
			for(int i = 0; i<_i; i++)
				for(int j = 0; j<_j; j++)
					a[i][j] = g++;
			g = 0;
			for(int j = 0; j<_j; j++)
				for(int i = 0; i<_i; i++)
					ans+=(a[i][j]==g++);
			fout << _i << ' ' << _j << ' ' << ans << '\n';
		}
		cout << _i << endl;
	}
	
	return 0;
}