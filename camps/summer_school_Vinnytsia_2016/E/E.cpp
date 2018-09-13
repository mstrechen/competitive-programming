#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>


using namespace std;

vector<int> connectedToH[1500], 
			connectedToV[1500];
			
bool usedH[1500],
	 usedV[1500];
			
			
int dfs(int current, bool isHorisontal)
{
	int res = 0;
	
	if(isHorisontal)
	{
		usedH[current] = 1;
		res+=connectedToH[current].size();
		for(int i = 0; i<connectedToH[current].size(); i++)
		{
			if(!usedV[connectedToH[current][i]])
			{
				res+=dfs(connectedToH[current][i], 0);
			}
		}
	}
	else
	{
		usedV[current] = 1;
		res+=connectedToV[current].size();
		for(int i = 0; i<connectedToV[current].size(); i++)
		{
			if(!usedH[connectedToV[current][i]])
			{
				res+=dfs(connectedToV[current][i], 1);
			}
		}
	}
	return res;
}
		
int main()
{
	ios::sync_with_stdio(false);
	
	int n, m, f, s;
	int x, y;
	
	
	cin >> n >> m >> f >> s;
	
	for(int i = 0; i<f; i++)
	{
		cin >> x >> y;
		connectedToV[x].push_back(y);
		connectedToH[y].push_back(x);
	}
	
	vector<int> connectivityComponent;
	
	for(int _i = 1; _i<=m; _i++)
	{
		if((!usedH[_i])&&connectedToH[_i].size())
		{
			connectivityComponent.push_back(dfs(_i, 1)/2);
		}
	}
	
	int resCount = min(s+1,(int)connectivityComponent.size());
	
	nth_element(connectivityComponent.begin(), 
				connectivityComponent.begin()+max(resCount-1,0),
				connectivityComponent.end(),
				greater<int>());
	
	int result = s;
	
	for(int i = 0; i<resCount; i++)
		result+=connectivityComponent[i];
	
	cout << min(result, n*m);
	
	return 0;
}