#include <iostream>
#include <cmath>
using namespace std;

int n;
int numbers[8]={0,0,0,0,0,0,0,0};

bool makeSomeCubicCollection(int n,int i)
{
	int cubicRoot=cbrt(n);
	if(i == 0)
		if (cubicRoot*cubicRoot*cubicRoot == n)
		{
			numbers[i] = cubicRoot;
			return true;
		}
		else
		{
			return false;
		}
	else 
		{
			int j;
			for(j = max(0, cubicRoot-2); j<=cubicRoot&&!makeSomeCubicCollection(n-j*j*j,i-1); j++){}
			if(j<=cubicRoot){numbers[i] = j; return true;}
			else return false;
		}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin >> n;
	if(makeSomeCubicCollection(n,7)){
		for(int i=0; i<=7; i++)
			if(numbers[i]>0) cout << numbers[i] << ' ';
	}
	else cout << -1;
return 0;
}