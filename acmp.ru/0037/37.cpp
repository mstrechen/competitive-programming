#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n, x1,x2,y1,y2;
	double q;
	bool answer = true;
	
	cin >> n >> q;
	for(int i = 0; i<n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		answer &= (x1*x1 + y1*y1 + 1e-7)*q*q>=x2*x2+y2*y2;
	}	
	if(answer)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	
	return 0;
}