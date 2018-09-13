#include <iostream>

using namespace std;
int segments[10] = {6,2,5,5,4,5,6,3,7,6};
int segmentsInt(int a)
{
	int answer=0;
	do
	{
		answer+=segments[a%10];
		a/=10;
	}while(a>0);
	return answer;
}
int main(){
	ios::sync_with_stdio(false);
	long long answer=0;
	int a, b;
	cin >> a >> b;
	for(int i = a; i<=b; i++)
	{
		answer+=segmentsInt(i);
	}
	cout << answer;
	return 0;
}