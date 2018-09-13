#include <iostream>
#include <algorithm>

using namespace std;

int cars[100];
int main(){
	ios::sync_with_stdio(false);
	int n,i, s;
	long long summOfCars=0;
	cin >> n >> s;
	for(int i = 0; i<n; i++)
	{
		cin >> cars[i];
	}
	stable_sort(cars, cars+n);
	for(i=0; (i<n)&&(summOfCars+cars[i]<=s);i++){
		summOfCars+=cars[i];
	}
	cout << i;
	return 0;
}