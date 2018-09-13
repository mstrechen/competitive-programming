#include <iostream>
#include <set>
#include <vector>


using namespace std;

const int INFINITY = 1e9;

int edges[100][100];
int dist[100];
bool isFinished[100];
set<pair<int,int>> datSetQueue;

int main(){
	ios::sync_with_stdio(false);
	int n, start, finish;
	
	cin >> n >> start >> finish;
	start--;
	finish--;
	
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
		pair<int,int> tmp = datSetQueue.begin();
	}
	
	return 0;
}