#include <iostream>
#include <set>
#include <vector>


using namespace std;

const int INFINITY = 1e9;

int edges[100][100];
int dist[100] = {INFINITY};
bool isFinished[100];
set<pair<int,int> > datSetQueue;

int main(){
	ios::sync_with_stdio(false);
	int n, start, finish;
	for(int i = 0; i<100; i++){dist[i] = INFINITY;};
	
	
	cin >> n >> start >> finish;
	start--;
	finish--;
	dist[start] = 0;
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cin >> edges[i][j];
		}
	}
	datSetQueue.insert(make_pair(0,start));
	for(;datSetQueue.size() > 0;)
	{
		pair<int,int> tmp = *datSetQueue.begin();
		int distance = tmp.first, currentNode = tmp.second;
		datSetQueue.erase(tmp);
		
		for(int i = 0; i<n; i++)
		{
			if(i!=currentNode&&edges[currentNode][i]>=0)
			{
				int currentDistance = dist[i];
				if(currentDistance > distance + edges[currentNode][i])
				{
					datSetQueue.erase(make_pair(currentDistance, i));
					datSetQueue.insert(make_pair(distance + edges[currentNode][i],i));
					dist[i] = distance + edges[currentNode][i];
				}
			}
		}
		
	}
	if(dist[finish]==INFINITY)
	{
		cout << -1;
	}
	else
	{
		cout << dist[finish];	
	}
	return 0;
}