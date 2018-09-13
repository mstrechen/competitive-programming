#include<stdio.h>
#include<cmath>
#include<vector>
 
using namespace std;
//

const pair<int,int> nothing  = {-2000000000, 2000000000};
 
pair<int,int> gcd(pair<int,int> a, pair<int,int> b)
{
    if(a.first==b.first)
		return a.second<b.second?a:b;
	return a.first>b.first?a:b;
}
 
struct SegmentTree
{
    vector<pair<int,int>  > _GCDs;
    int _size;
 
    SegmentTree(int n)
    {
        int i  = 1;
        while(i<n) i*=2;
        _size = i;
        _GCDs = vector<pair<int,int> >(_size*2, nothing);
		
    }
 
    void build(int n)
    {
        for(int i = 0; i<n; i++)
        {
            scanf("%d",&_GCDs[i+_size].first);
			_GCDs[i+_size].second = i+1;
        }
        for(int i = _size-1; i>0; i--)
        {
            _GCDs[i] = gcd(_GCDs[i*2], _GCDs[i*2+1]);
        }
    }
 
    pair<int,int> _getGCD(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
            return nothing;
        if(l==minL&&r==maxR)
            return _GCDs[_i];
        int mid = (minL+maxR)/2;
        return gcd(_getGCD(l, min(mid,r), minL, mid, _i*2),
                   _getGCD(max(mid+1,l), r, mid+1, maxR, _i*2+1));
    }
    pair<int,int> getGCD(int l, int r)
    {
        return _getGCD(l,r,1,_size,1);
    }
};
 
 
int main()
{
 
    int n;
    scanf("%d", &n);
 
    SegmentTree ST(n);
    ST.build(n);
 
    int m;
    int l, r;
 
    scanf("%d", &m);
 
    for(int i = 0; i<m; i++)
    {
        scanf("%d%d", &l, &r);
		auto tmp  = ST.getGCD(l,r);
        printf("%d %d\n", tmp.first, tmp.second);
    }
    return 0;
}