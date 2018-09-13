#include <iostream>

using namespace std;
int v[100];

int main(){
	ios::sync_with_stdio(false);
	int n,k,tmp;
	cin >> n;
	for(int i=0; i<n;i++) cin >> v[i];
	for(int i=0; i<n; i++)
	{
		cin >> tmp;
		v[i]*=tmp;
	}
	k=0;
	for(int i = 1; i<n; i++)
		if(v[i]>v[k]){
			k=i;
		}
	cout << k+1;
	return 0;
}