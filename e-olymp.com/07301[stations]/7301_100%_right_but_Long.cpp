#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <ctime>
using namespace std;
bool isMore(long long a, long long b)
	{
		return a>b;	
	}
long long spans[1000];
int main(){
	//ifstream cin("input.txt");
	
	memset(spans, 0, sizeof(spans));
	ios::sync_with_stdio(false);
	int n,m,tmp;
	
	long long summ=0;
	double be = clock();
	cin >> n >> m;
	for(int i = 1; i<n; i++)
	{
		for(int j = 0; j<i; j++)
		{
			cin >> tmp;
			summ+=tmp;
			for(int k = j; k<i; k++)
			{
				spans[k]+=tmp;
			}
			
		}
		
	}
	stable_sort(spans, spans+n-1, isMore);
	
	for(int i = 0; i<m-1; i++)
	{
		summ+=spans[i];
	}
	cout << summ;
	double en = clock();
	//cout << "\nTIME:" << (en-be)/CLOCKS_PER_SEC;
	return 0;
}