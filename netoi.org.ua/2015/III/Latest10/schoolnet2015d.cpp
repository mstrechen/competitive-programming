#include <iostream>
#include <cmath>
using namespace std;

const int MAX_COUNT=20000;

struct listOfEdges{
	int g[MAX_COUNT],sizeOfList;
	int size()
	{
		return sizeOfList;
	}
	void incSize()
	{
		sizeOfList++;
	}
	int &operator [](int n)
	{
		return g[n];
	}
} g[MAX_COUNT];

bool used[MAX_COUNT];

int timer, tin[MAX_COUNT], fup[MAX_COUNT];
int countOfBriges=0;
void dfs(int v, int p = -1)
{
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i=0; i<g[v].size(); ++i)
	{
		int to = g[v][i];
		
		if (to == p) 
		{
			continue;
		}
		if (used[to])
		{
			fup[v] = min(fup[v],tin[to]);
		}
		else
		{
			dfs(to, v);
			fup[v] = min(fup[v],fup[to]);
			
			if (fup[to] > tin[v])
			{
				countOfBriges++;
			}
		}
	}
}
 
void findAllBridges(int n) {
	timer = 0;
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
}

int main(){
	ios::sync_with_stdio(false);
	int n, m,tmpFrom,tmpTo;
	cin >> n >> m;
	for(int i =0; i<m; i++)
	{
		cin >> tmpFrom >> tmpTo;
		g[tmpFrom-1][g[tmpFrom-1].size()] = tmpTo-1;
		g[tmpFrom-1].incSize();
		g[tmpTo-1][g[tmpTo-1].size()] = tmpFrom-1;
		g[tmpTo-1].incSize();
		
	}
	findAllBridges(n);
	cout << m-countOfBriges;
	return 0;
}