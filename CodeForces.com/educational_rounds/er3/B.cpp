#include <iostream>
#include <vector>
using namespace std;

vector<int> genres(10);
int main(){
	ios::sync_with_stdio(false);
	int n,m,tmp;
	int answer=0;
	cin >> n >> m;
	for(int i=0;i<n; i++)
	{
		cin >> tmp;
		genres[tmp-1]++;
	}
	for(int i =0; i<m; i++)
		for(int j=i+1; j<m; j++)
			answer+=genres[i]*genres[j];
	cout << answer;
	return 0;
}