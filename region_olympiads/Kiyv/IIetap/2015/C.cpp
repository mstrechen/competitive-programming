#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int numbers[200002];
bool wereInSeq[200002];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	ios::sync_with_stdio(false);
	int n,doubleN,count,lastIncluded,difference;
	cin >> n;
	for(int i = 2*n-1; i>=0; i--)
	{
		cin >> numbers[i];
	}
	sort(numbers,numbers+2*n);
	
	
	count = 1;
	lastIncluded = 0;
	difference = numbers[1]-numbers[0];
	for(int i = 0; i<2*n&&count<n; i++)
	{
		if(numbers[i]-numbers[lastIncluded]==difference)
		{
			lastIncluded = i;
			count++;
		}
	}
	if(count == n)
	{	
		count = 1;
		lastIncluded = 0;
		wereInSeq[lastIncluded] = true;
		cout << numbers[lastIncluded] << ' ';
		
		for(int i = 0; i<2*n&&count<n; i++)
		{
			if(numbers[i]-numbers[lastIncluded]==difference)
			{
				lastIncluded = i;
				cout << numbers[i] << ' ';
				wereInSeq[i] = true;
				count++;
			}
		}
		cout << '\n';		
		for(int i = 0; i<2*n; i++)
		{
			if(!wereInSeq[i])
			{
				cout << numbers[i] << ' ';
			}
		}
		return 0;
	}
	
	count = 1;
	lastIncluded = 0;
	difference = numbers[2]-numbers[0];
	for(int i = 0; i<2*n; i++)
	{
		if(numbers[i]-numbers[lastIncluded]==difference)
		{
			lastIncluded = i;
			count++;
		}
	}
	if(count == n)
	{	
		lastIncluded = 0;
		wereInSeq[lastIncluded] = true;
		cout << numbers[lastIncluded] << ' ';
		
		for(int i = 0; i<2*n; i++)
		{
			if(numbers[i]-numbers[lastIncluded]==difference)
			{
				lastIncluded = i;
				cout << numbers[i] << ' ';
				wereInSeq[i] = true;
			}
		}
		cout << '\n';		
		for(int i = 0; i<2*n; i++)
		{
			if(!wereInSeq[i])
			{
				cout << numbers[i] << ' ';
			}
		}
		return 0;
	}
	
	count = 1;
	lastIncluded = 1;
	difference = numbers[2]-numbers[1];
	for(int i = 0; i<2*n&&count<n; i++)
	{
		if(numbers[i]-numbers[lastIncluded]==difference)
		{
			lastIncluded = i;
			count++;
		}
	}
	if(count == n)
	{	
		lastIncluded = 1;
		wereInSeq[lastIncluded] = true;
		count = 1;
		for(int i = 0; i<2*n&&count<n; i++)
		{
			if(numbers[i]-numbers[lastIncluded]==difference)
			{
				lastIncluded = i;
				wereInSeq[i] = true;
				count++;
			}
		}	
		for(int i = 0; i<2*n; i++)
		{
			if(!wereInSeq[i])
			{
				cout << numbers[i] << ' ';
			}
		}
		cout << '\n';		
		for(int i = 0; i<2*n; i++)
		{
			if(wereInSeq[i])
			{
				cout << numbers[i] << ' ';
			}
		}
		
		return 0;
	}
	
return 0;
}