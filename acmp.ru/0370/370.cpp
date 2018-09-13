#include <iostream>
#include <cmath>
using namespace std;

int getDoubleSizeOfTrapeze(pair<int,int> a, pair<int,int> b)
{
	return (a.first + b.first)*(b.second - a.second);
} 

int main(){
	ios::sync_with_stdio(false);
	int n,tmpX,tmpY;
	long long summ = 0;
	pair<int,int> firstPoint, nextPoint, prevPoint;
	
	cin >> n;
	cin >> tmpX >> tmpY;
	firstPoint = make_pair(tmpX,tmpY);
	nextPoint = firstPoint;
	for(int i = 1; i<n; i++)
	{
		prevPoint = nextPoint;
		cin >> tmpX >> tmpY;
		nextPoint = make_pair(tmpX,tmpY);
		summ+=getDoubleSizeOfTrapeze(prevPoint,nextPoint);
	}
	summ+=getDoubleSizeOfTrapeze(nextPoint,firstPoint);
	summ = abs(summ);
	cout << summ/2 << '.' << (summ%2)*5;
return 0;
}