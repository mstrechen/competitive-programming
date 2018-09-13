#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
	int from, to, value;
	edge(int from = 0, int to = 0, int value = 0) : from(from), to(to), value(value)
	{}
};
bool isEdgeMore(edge a, edge b)
{
	return a.value < b.value;
}

int parent[101];
int sizeOfSet[101];

int getParent(int a)
{
	for(; parent[a]!=a; a = parent[a]){}
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m,answer = 0;
	cin >> n >> m;
	vector<edge> allEdges(m);
	for(int i = 0; i<m; i++)
	{
		cin >> allEdges[i].from >> allEdges[i].to >> allEdges[i].value;
	}
	for(int i = 1; i<=n; i++)
	{
		parent[i] = i;
	}
	sort(allEdges.begin(),allEdges.end(), isEdgeMore);
	int j = 0;
	for(int i = 0; i+1<n; i++)
	{
		int currentFrom, currentTo;
		do
		{
			currentFrom = getParent(allEdges[j].from);
			currentTo = getParent(allEdges[j].to);
			j++;
		}
		while(currentFrom==currentTo);
		
		if(sizeOfSet[currentFrom]==sizeOfSet[currentTo])
		{
			sizeOfSet[currentFrom]++;
		}
		if(sizeOfSet[currentFrom]>sizeOfSet[currentTo])
		{
			parent[currentTo] = currentFrom;
		}
		else
		{
			parent[currentFrom] = currentTo;
		}
		answer += allEdges[j-1].value;
	}
	cout << answer;
	return 0;
}