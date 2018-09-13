#include <stdio.h>
#include <vector>

using namespace std;


const int INF = 1000000009;

struct SegmentTree
{
	int _size;
	vector<int> maximals, added;
	
	SegmentTree(int n)
	{
		int size = 1;
		
		while(size<n)
			size*=2;
		
		_size = size;
		
		maximals = added = vector<int>(size*2,0);
	}
	
	int _getMin(int l, int r, int minL, int maxR, int _i)
	{
		if(l>r)
			return 0;
		if(l==minL&&r==maxR)
			return maximals[_i]+added[_i];
		int mid = (minL+maxR)/2;
		return added[_i]+max(_getMin(l, min(mid,r), minL, mid, _i*2),
							 _getMin(max(mid+1, l), r, mid+1, maxR, _i*2+1));
	}
	
	int getMin(int l, int r)
	{
		return _getMin(l, r, 1, _size, 1);
	}
	
	int _update(int l, int r, int minL, int maxR, int _i, int value)
	{
		if(l>r)
			return maximals[_i]+added[_i];
		if(l==minL&&r==maxR)
		{
			added[_i]+=value;
			return maximals[_i]+added[_i];
		}
		int mid = (minL+maxR)/2;
		maximals[_i] = max(_update(l, min(mid,r), minL, mid, _i*2, value),
						   _update(max(mid+1,l), r, mid+1, maxR, _i*2+1, value));
		return maximals[_i]+added[_i];
	}
	void update(int l, int r, int value)
	{
		_update(l, r, 1, _size, 1, value);
	}
	
	bool getAnswer(int l, int r, int k)
	{
		if(getMin(l,r)<k)
		{
			update(l,r,1);
			return 1;
		}
		
		return 0;
	}
};

int main(){
	
	int n, k, m;
	int tmpBe, tmpEn;
	
	scanf("%d%d%d", &n,&k,&m);
	SegmentTree st(n-1);
	
	for(int i = 0; i<m; i++)
	{
		scanf("%d%d", &tmpBe, &tmpEn);
		printf(st.getAnswer(tmpBe+1, tmpEn, k)?"Yes\n":"No\n");
		
	}
	return 0;
}