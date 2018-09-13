#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,tmp,howLong=0;
	long long answer=1;
	bool wasA=0;
	cin >> n;
	
	for(int i = 0; i<n; i++)
	{
		cin >> tmp;
		howLong+=(tmp==0);
		if(tmp==1&&wasA)
		{
			answer*=howLong+1;
		}
		if(tmp==1)
		{
			howLong = 0;
		}
		wasA|=(tmp==1);
	}
	cout << answer*wasA;
	return 0;
}