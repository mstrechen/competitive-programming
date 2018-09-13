#include <iostream>
#include <algorithm>
#include <vector>
#define ull unsigned long long
using namespace std;

vector <ull> disks;
ull countOfEveryDisk[64];
int main(){
	ios::sync_with_stdio(false);
	ull n,tmp,countOfDifferent=1,last,answer=0;
	
	cin >> n;
	for(int i = 0; i<n;i++)
	{
		cin >> tmp;
		disks.push_back(tmp);
	}
	stable_sort(disks.begin(),disks.end());
	last = disks[0];
	countOfEveryDisk[0] = 1;
	for(int i = 1; i<n; i++)
	{
		if(disks[i]==last){
			countOfEveryDisk[countOfDifferent-1]++;
		}
		else{
			countOfEveryDisk[countOfDifferent] = 1;
			countOfDifferent++;
			last = disks[i];
		}
	}
	for(ull i =0; i<countOfDifferent;i++)
	{
		answer+=countOfEveryDisk[countOfDifferent-i-1] << i;
	}
	cout << answer;
	return 0;
}