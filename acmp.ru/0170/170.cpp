#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	int answer;
	
	cin >> n;
	for(int i = 1; i*(i-1)<n*2;i++)
	{
		if((n-(i*(i-1)>>1))%i==0)
		{
			answer = i;
		}
	}
	cout << answer;
	return 0;
}