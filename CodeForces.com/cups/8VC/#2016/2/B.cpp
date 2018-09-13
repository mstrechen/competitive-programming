#include <iostream>

using namespace std;

int mems1[200000], mems2[200000];
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n;
	n--;
	for(int i = 0; i<n; i++)
	{
		cin >> mems1[i];
		if(mems1[i]==0)
		{
			i--;
		}
	}
	for(int i = 0; i<n; i++)
	{
		cin >> mems2[i];
		if(mems2[i]==0)
		{
			i--;
		}
	}
	for(k = 0; mems1[k]!=mems2[0]; k++){}
	for(int i=0;i<n; i++)
	{
		if(mems2[i]!=mems1[k])
		{
			cout << "NO";
			return 0;
		}
		k++;
		if(k==n)
		{
			k=0;
		}
	}
	cout << "YES";
	return 0;
}