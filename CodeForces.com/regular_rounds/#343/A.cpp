#include <iostream>

using namespace std;

int hashv[200], hashh[200];
int main(){
	ios::sync_with_stdio(false);
	char c;
	int n;
	long long answer = 0;
	cin >> n;
	for(int i = 0; i<n; i++)
		for(int j =0; j<n; j++)
		{
			cin >> c;
			if(c=='C')
			{
					
			hashv[j]++;
			hashh[i]++;
			}
		}
	for(int i = 0; i<n; i++)
	{
		answer+=hashv[i]*(hashv[i]-1)/2;
		answer+=hashh[i]*(hashh[i]-1)/2;
	}
	cout << answer;
	return 0;
}