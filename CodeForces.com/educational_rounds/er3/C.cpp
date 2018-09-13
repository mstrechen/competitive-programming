#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> tasks;

int main(){
	ios::sync_with_stdio(false);
	int n,result=0,summ=0,tmp;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> tmp;
		summ+=tmp;
		tasks.push_back(tmp);
	}
	
	stable_sort(tasks.begin(),tasks.end());
	tmp = summ % n;
	summ/=n;
	for(int i = n-tmp; i<n; i++){
		result+=abs(summ+1-tasks[i]);
	}
	for(int i =0; i<n-tmp; i++){
		result+=abs(summ-tasks[i]);
	}
	cout << result/2;
	return 0;
}