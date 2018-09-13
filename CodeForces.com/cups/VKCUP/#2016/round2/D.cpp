#include <iostream>
#include <cmath>

using namespace std;

double minA[100000], maxA[100000], a[100000], b[100000];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> maxA[i];
	}
	for(int i = 0; i<n; i++)
	{
		cin >> minA[i];
		minA[i]+=maxA[i];
	}
	double k1 = 0, k2 = 0,a,b,x,y,d,y1,y2;
	
	for(int i = 0; i<n; i++)
	{

		a = minA[i];
		b = maxA[i];
		d = sqrt((a-k1+k2)*(a-k1+k2)+4*(a*k1-b));
		y1 = (a+k2-k1-d)/2;
		y2 = (a+k2-k1+d)/2;
		if(0<=y2&&y2<=1)
			y = y2;
		else
			y = y1;
		x = a-y;
		k2+=x;
		k1+=y;
		minA[i] = x;
		maxA[i] = y;
	}
	for(int i = 0; i<n; i++)
	{
		cout << minA[i] << ' ';
	}
	cout << '\n';
	for(int i = 0; i<n; i++)
	{
		cout << maxA[i] << ' ';
	}
	return 0;
}