#include<stdio.h>
#include<cmath>
#include<vector>

using namespace std;
//

long long gcd(long long a, long long b)
{
    return a+b;
}

struct SegmentTree
{
    vector<long long> _GCDs;
    int _size;

    SegmentTree(int n)
    {
        int i  = 1;
        while(i<n) i*=2;
        _size = i;
        _GCDs = vector<long long>(_size*2,0);
    }

    void build(int n)
    {
        for(int i = 0; i<n; i++)
        {
            scanf("%I64d",&_GCDs[i+_size]);
        }
        for(int i = _size-1; i>0; i--)
        {
            _GCDs[i] = gcd(_GCDs[i*2], _GCDs[i*2+1]);
        }
    }

    long long _getGCD(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
            return 0;
        if(l==minL&&r==maxR)
            return _GCDs[_i];
        int mid = (minL+maxR)/2;
        return gcd(_getGCD(l, min(mid,r), minL, mid, _i*2),
                   _getGCD(max(mid+1,l), r, mid+1, maxR, _i*2+1));
    }


	long long _setGCD(int i, int v, int minL, int maxR, int _i)
    {
        if(i<minL||i>maxR)
            return _GCDs[_i];
        if(minL==maxR)
            return _GCDs[_i]+= v;
        int mid = (minL+maxR)/2;
        return _GCDs[_i] = gcd(_setGCD(i, v , minL, mid, _i*2),
                   _setGCD(i,v , mid+1, maxR, _i*2+1));
    }
	long long setGCD(int i, int v)
    {
        return _setGCD(i,v,1,_size,1);
    }
    long long getGCD(int l, int r)
    {
        return _getGCD(l,r,1,_size,1);
    }
};


int main()
{

    int n;
    scanf("%d ", &n);

    SegmentTree ST(n);

    int m;
    int l, r;
	char c;
    scanf("%d", &m);

    for(int i = 0; i<m; i++)
    {
        scanf(" %c%c%c %d %d", &c,&c,&c, &l, &r);
		if(c=='q')
			printf("%I64d\n",ST.getGCD(l,r));
		else
			ST.setGCD(l,r);
    }
    return 0;
}
