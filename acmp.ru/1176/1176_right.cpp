#include <stdio.h>
#include <vector>

using namespace std;

const int INF = 1000000009;

struct  SegmentTreeSumm
{
	vector<int> mins;
	int _size;

	SegmentTreeSumm(int n)
	{
		_size = 1;
		while(_size<n)
			_size*=2;
		mins = vector<int>(_size*2, INF);
	}

	SegmentTreeSumm operator + (SegmentTreeSumm a)
	{
		for(unsigned int i = 0; i<a.mins.size(); i++)
		{
			a.mins[i] = min(this->mins[i], a.mins[i]);
		}
		return a;
	}

	void build(int n)
	{
		for(int i = 0; i<n; i++)
		{
			scanf("%d", &mins[i+_size]);
		}
		for(int i = _size-1; i>0; i--)
		{
			mins[i] = min(mins[i*2],mins[i*2+1]);
		}
	}

	int _getMin(int l, int r, int minL, int maxR, int _i)
	{
		if(l>r)
			return INF;
		if(l==minL&&r==maxR)
			return mins[_i];
		int mid = (minL+maxR)/2;
		return  min(_getMin(l, min(mid,r), minL, mid, _i*2),
					_getMin(max(l, mid+1), r, mid+1, maxR, _i*2+1));
	}

	int getMin(int l, int r)
	{
		return _getMin(l,r,1,_size,1);
	}

};

struct  SegmentTreeSumm2d
{
	vector<SegmentTreeSumm> mins;
	int _size;

	SegmentTreeSumm2d(int n, int m)
	{
		_size = 1;
		while(_size<n)
			_size*=2;
		mins = vector<SegmentTreeSumm>(_size*2, SegmentTreeSumm(m));
	}
	void build(vector<SegmentTreeSumm> & lines)
	{
		for(unsigned int i = 0; i<lines.size(); i++)
		{
			mins[i+_size] = lines[i];
		}
		for(int i = _size-1; i>0; i--)
		{
			mins[i] = mins[i*2]+mins[i*2+1];
		}
	}

	int _getMin(int l, int r, int minL, int maxR, int _i, int x, int y)
	{
		if(l>r)
			return INF;
		if(l==minL&&r==maxR)
			return mins[_i].getMin(x,y);
		int mid = (minL+maxR)/2;
		return  min(_getMin(l, min(mid,r), minL, mid, _i*2,x,y),
				_getMin(max(l, mid+1), r, mid+1, maxR, _i*2+1,x,y));
	}

	int getMin(int l, int r, int x, int y)
	{
		return _getMin(l,r,1,_size,1, x, y);
	}

};




int main()
{
	int n, m, k;

	scanf("%d%d%d", &n, &m, &k);
	vector<SegmentTreeSumm> lines(n, SegmentTreeSumm(m));

	for(int i = 0; i<n; i++)
		lines[i].build(m);

	SegmentTreeSumm2d st(n,m);
	st.build(lines);

	int x1, y1, x2, y2;
	for(int i = 0; i<k; i++)
	{
		scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
		printf("%d\n", st.getMin(x1,x2,y1,y2));
	}

	return 0;
}
