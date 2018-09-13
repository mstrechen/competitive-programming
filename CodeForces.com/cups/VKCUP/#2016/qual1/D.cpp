#include <iostream>
#include <algorithm>
using namespace std;

const int BFI = 1000000;

int barriers[BFI];
int steps[BFI];
bool allowedToRun[BFI];
int main(){
	ios::sync_with_stdio(false);
	
	int n, m, lengthOfJump, lengthOfPreparing, lastPoint = 1;
	int countOfSteps = 1;
	
	cin >> n >> m  >> lengthOfPreparing >> lengthOfJump;
	
	for(int i = 0; i<n; i++)
	{
		cin >> barriers[i];
		
	}
	barriers[n] = -1;
	barriers[n+1] = m+1;
	sort(barriers, barriers+n+1);
	
	for(int i = 0; i<n; i++)
	{
		allowedToRun[i] = (barriers[i+1]-barriers[i]-2>=lengthOfPreparing);
	}
	allowedToRun[n] = 1;
	if(allowedToRun[0]==0)
	{
		cout << "IMPOSSIBLE"; 
		return 0;
	}
	
	
	steps[0] = barriers[1]-1;
	for(int i = 1; i<n+1; i++)
	{
		if(allowedToRun[i])
		{
			steps[countOfSteps++] = barriers[i] - barriers[lastPoint]+2;
			if(steps[countOfSteps-1] > lengthOfJump)
			{
				cout << "IMPOSSIBLE";
				return 0;
			}
			steps[countOfSteps++] = barriers[i+1]-barriers[i]-2;
			lastPoint = i+1;
		}
	}
	
	
	for(int i = 0; i<countOfSteps; i++)
	{
		if(steps[i]==0)
		{
			break;
		}
		if(!(i&1))
		{
			cout << "RUN ";
		}
		else
		{
			cout << "JUMP ";
		}
		cout << steps[i] << '\n';
	}
	return 0;
}