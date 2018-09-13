#include <stdio.h>
#include <vector>

using namespace std;

struct segment_tree{
	
	int _size;
	vector<long long> added;
	
	segment_tree(int n){
		_size = 1;
		while(_size<n)
			_size*=2;
		added = vector<long long>(_size*2, 0);
	}
	
	long long get(int i, int l, int r, int _i){
		if(l==r)
			return added[_i];
		int mid = (l+r)/2;
		if(i<=mid)
			return get(i,l, mid, _i*2)+added[_i];
		else
			return get(i, mid+1, r, _i*2+1)+added[_i];
	}
	
	long long get(int i){
		return get(i, 1,_size, 1);
	}
	
	void update(int l, int r, int minL, int maxR, int _i, int value)
	{
		if(l>r)
			return;
		if(l==minL&&r==maxR)
			added[_i]+=value;
		else
		{
			int mid = (minL+maxR)/2;
			update(l,min(mid,r), minL, mid, _i*2, value);
			update(max(mid+1,l),r, mid+1, maxR, _i*2+1, value);
		}
	}
	void update(int l, int r, int value)
	{
		update(l, r, 1,_size, 1, value);
	}
};


int main(){
	
	int n,m;
	
	scanf("%d", &n);
	
	vector<long long> a(n);
	segment_tree st(n);
	
	for(int i = 0; i<n; i++)
	{
		scanf("%I64d", &a[i]);
	}
	
	scanf("%d", &m);
	
	for(int i = 0; i<m; i++)
	{
		char c = getchar();
		while(c!='g'&&c!='a')
			c = getchar();
		
		if(c=='g')
		{
			int x;
			scanf("%d", &x);
			printf("%I64d ", st.get(x)+a[x-1]);
		}
		else
		{
			int x, y, delta;
			scanf("%d%d%d", &x, &y, &delta);
			st.update(x,y,delta);
		}
	}
	
	return 0;
}