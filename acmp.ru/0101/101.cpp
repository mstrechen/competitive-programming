#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int stack[50];
int nOfMags = 0,nOfMagsWhatShouldBe;
int answer = 0;

bool allIsOk(int i, int y)
{
	if(y==0)
	{
		return true;
	}
	for(int  j =  1; j < i; j++)
	{
		if(stack[j]==y)
		{
			return false;
		}
		
		if(stack[j]!=0)
		{
			if(i-j==1&& abs(stack[j]-y)==2)
			{
				return false;
			}
			if(i-j==2&& abs(stack[j]-y)==1)
			{
				return false;
			}
			if(stack[j]-j==y-i||stack[j]+j==y+i)
			{
				return false;
			}
		}
		
	}
	return true;
}

void countOfMethods(int n,int i)
{
	if(n==i||nOfMags==nOfMagsWhatShouldBe)
	{
		answer+=(nOfMags==nOfMagsWhatShouldBe);
		if(nOfMags==nOfMagsWhatShouldBe){for(int j = 1; j<=n; j++)
		{
			cout << stack[j] << ' ';
		}
		cout <<'\n';}
		return;
	}
	else
	{
		stack[i+1] = 0;
		countOfMethods(n,i+1);
		
		nOfMags++;
		for(int j = 1; j<=n; j++)
		{
			if(allIsOk(i+1,j))
			{
				stack[i+1] = j;
				countOfMethods(n, i+1);
			}
		}
		nOfMags--;
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> nOfMagsWhatShouldBe;
	double be=clock();
	countOfMethods(n,0);
	cout << answer;
	double en = clock();
	cout << "\nTIME:" << (en-be)/CLOCKS_PER_SEC;
	return 0;
}