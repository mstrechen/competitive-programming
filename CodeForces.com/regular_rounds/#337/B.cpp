#include <iostream>
#include <cmath>
using namespace std;
int colors[200000];
int listOfMinSizes[200000];
int main(){
	ios::sync_with_stdio(false);
	int n, minimal = 0, countOfMin=0, maxDelta;
	cin >> n;
	
	cin >> colors[0];
	for(int i = 1; i<n; i++)
	{
		cin >> colors[i];
		if(colors[minimal]>colors[i])
		{
			minimal =  i;
		}
	}
	
	
	for(int i = 0; i< n; i++)
	{
		if(colors[i] == colors[minimal])
		{
			listOfMinSizes[countOfMin] = i;
			countOfMin++;
		}
	}
	maxDelta = listOfMinSizes[0]+n-listOfMinSizes[countOfMin-1]-1;
	for(int i = 1; i<countOfMin;i++)
	{
		maxDelta = max(maxDelta, listOfMinSizes[i]-listOfMinSizes[i-1]-1);
	}
	cout << (long long)colors[minimal]*n + maxDelta;
	return 0;
}