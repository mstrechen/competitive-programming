#include <iostream>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,m,curr_min, tmp,globalMax=0;
	cin >> n >> m;
	for(int i = 0; i<n; i++)
	{
		cin >> curr_min;
		for(int j = 1; j<m; j++)
		{
			cin >> tmp;
			curr_min = min(curr_min, tmp);
		}
		globalMax = max(globalMax,curr_min);
	}
	cout << globalMax;
	return 0;
}