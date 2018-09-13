#include <iostream>
#include <set>
using namespace std;

int perl[300000];
set<int> numbersInCurrent;
int listOfSegments[300000][2];
int main(){
	ios::sync_with_stdio(false);
	int n,lastI = 0,count=0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> perl[i];
	}
	for(int i = 0; i<n; i++)
	{
		if(numbersInCurrent.count(perl[i])==1)
		{
			listOfSegments[count][0] = lastI;
			listOfSegments[count][1] = i;
			lastI = i+1;
			count++;
			numbersInCurrent.clear();
		}
		else
		{
			numbersInCurrent.insert(perl[i]);
		}
	}
	if(count == 0)
	{
		cout << -1;
	}
	else
	{
		cout << count << '\n';
		for(int i = 0; i<count-1; i++)
		{
			cout << listOfSegments[i][0]+1 << ' ' << listOfSegments[i][1]+1 << '\n';
		}
		cout << listOfSegments[count-1][0]+1 << ' ' << n << '\n';
	}
	
	return 0;
}