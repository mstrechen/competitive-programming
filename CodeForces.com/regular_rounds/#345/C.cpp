#include <iostream>
#include <map>
#include <set>
using namespace std;

map<int,int> x, y;
map<int,int>::iterator it;
map<pair<int,int>,int> mapOfGuys;
map<pair<int,int>,int>::iterator anotherIt;

int main(){
	ios::sync_with_stdio(false);
	int n,tmpX, tmpY;
	long long answer = 0, countOfSame=0;
	pair<int,int> tmp;
	long long tmpDob;
	pair<pair<int,int>,int> tmp2;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> tmpX >>  tmpY;
		x[tmpX]++;
		y[tmpY]++;
		mapOfGuys[make_pair(tmpX,tmpY)]++;
	}
	for(it = x.begin(); it!=x.end(); it++)
	{
		tmp = *it;
		tmpDob = tmp.second;
		answer+=tmpDob*(tmpDob-1)/2;
	}
	for(it = y.begin(); it!=y.end(); it++)
	{
		tmp = *it;
		tmpDob = tmp.second;
		answer+=tmpDob*(tmpDob-1)/2;
	}
	for(anotherIt = mapOfGuys.begin(); anotherIt!=mapOfGuys.end(); anotherIt++)
	{
	    tmp2 = *anotherIt;
        tmpDob = tmp2.second;
		countOfSame+=tmpDob*(tmpDob - 1)/2;
	}
	cout << answer-countOfSame;
	return 0;
}
