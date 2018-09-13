#include <stdio.h>
#include <vector>
#include <iostream>

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

	void build(vector<vector<int> > & field, int n, int _i, int x2, int y2)
	{
		for(int i = 1; i<=n; i++)
		{
			mins[i+_size] = field[_i+x2-1][i+y2-1]+
                            field[_i-1][i-1]-
                            field[_i+x2-1][i-1]-
                            field[_i-1][i+y2-1];
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
	int n, m, x1, y1, x2, y2;

	scanf("%d%d%d%d%d%d", &m, &n, &y1, &x1, &y2, &x2);

    vector<vector<int> > field(1005, vector<int>(1005,0));

    int realN = n-x2+1, realM = m-y2+1;
    int bigN = n-x1+1, bigM = m-y1+1;


    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            scanf("%d",&field[i][j]);

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            field[i][j]+= field[i][j-1]+field[i-1][j]-field[i-1][j-1];

	vector<SegmentTreeSumm> lines(realN+1, SegmentTreeSumm(realM));

	for(int i = 1; i<=realN; i++)
		lines[i].build(field, realM, i, x2, y2);

	SegmentTreeSumm2d st(realN,realM);
	st.build(lines);


	int maxSize = 0;


	int deltaX = x1-x2-2, deltaY = y1-y2-2;

	for(int i = 1; i<=bigN; i++)
        for(int j = 1; j<=bigM; j++)
        {
            maxSize = max(maxSize,
                          field[i-1][j-1]+
                          field[i+x1-1][j+y1-1]-
                          field[i-1][j+y1-1]-
                          field[i+x1-1][j-1]-
                          st.getMin(i+1,j+1,i+1+deltaX,j+1+deltaY));

        }
    printf("%d",maxSize);
	return 0;
}
