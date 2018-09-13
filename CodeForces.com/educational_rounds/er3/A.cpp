#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> flashes;
int main(){
	ios::sync_with_stdio(false);
	int n,m,tmp;
	cin >> n >> m;
	for(int i = 0; i<n; i++)
	{
			cin >> tmp;
			flashes.push_back(tmp);
	}
	
	stable_sort(flashes.begin(), flashes.end());
	int summ = 0,i;
	for(i = n-1;summ<m; i-- ){ summ+=flashes[i];}
	cout << (n-i-1);
	
	return 0;
}