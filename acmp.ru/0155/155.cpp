#include <iostream>
#include <vector>
#include <math>
using namespace std;

double prec(vector<double> v)
{
	
}

double c[7];
int main(){
	ios::sync_with_stdio(false);
	int n;
	double req;
	cin >> n >> req;
	
	for(int i = 0; i<n; i++)
	{
		cin << c[i];
	}
	if(n==1)
	{
		if(max(c[0],req)-min(c[0],req)<0.1)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}
	for(int i = 1>>n)
	return 0;
}