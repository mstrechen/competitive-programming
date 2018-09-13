#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>

using namespace std;

struct dsu
{
	int n;
	vector<int> _p, _treeSize;
	
	dsu(int n):n(n+1), _p(n+1), _treeSize(n+1,0)
	{
		for(int i = 0; i<=n; i++)
			this->_p[i]=i;
	}
	
	int _getParent(int i)
	{
		if(_p[i]==i)
			return i;
		return (_p[i]=_getParent(_p[i]));
	}
	
	void unite(int i, int j)
	{
		i = _getParent(i);
		j = _getParent(j);
		if(i!=j)
		{
			_p[j] = i;
			_treeSize[i]+=_treeSize[j]+1;
			_treeSize[j] = 0;
		}
		else
		{
			_treeSize[i]++;
		}
	}
	
	int getMaxSize(int n)
	{
		nth_element(_treeSize.begin(), 
				_treeSize.begin()+max(n-1,0),
				_treeSize.end(),
				greater<int>());
		
		return accumulate(_treeSize.begin(), _treeSize.begin()+n, 0);
	}
};
		
		
int main()
{
	int n, m, f, s;
	int x, y;
	
	scanf("%d%d%d%d", &n,&m,&f,&s);
	
	dsu components(n+m+2);
	
	for(int i = 0; i<f; i++)
	{
		scanf("%d%d",&x,&y);
		components.unite(x,n+y);
	}
	
	
	int result = s+components.getMaxSize(min(s+1,n+m+1));
	
	printf("%d",min(result, n*m));
	
	return 0;
}