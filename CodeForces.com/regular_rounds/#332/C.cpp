#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct castle{
	int startPos,h;
} castles[100000];

bool compareThisShit(castle a, castle b)
{
	if(a.h==b.h)
	{
		return  a.startPos < b.startPos;
	}
	else
	{
		return a.h < b.h;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n,countOfCastles=0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> castles[i].h;
		castles[i].startPos = i;
	}
	sort(castles,castles+n,compareThisShit);
	int lastHit = castles[0].startPos;
		countOfCastles+=(lastHit == 0);
	for(int i = 1; i<n; i++)
	{
		lastHit = max(lastHit, castles[i].startPos);
		countOfCastles+=(lastHit == i);
	}
	cout << countOfCastles;
	return 0;
}