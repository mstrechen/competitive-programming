#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 1000000009;


vector<pair<int,int> >  a,b;


struct SegmentTree
{
    vector<int> mins;
    int _size;

    SegmentTree(int a)
    {
        _size = 1;
        while(_size<a)
            _size*=2;
        mins = vector<int>(_size*2, INF);
    }
    void build(int n, vector<int> & a)
    {
        for(int i = 0; i<n; i++)
        {
            mins[i+_size] = a[i];
        }
        for(int i = _size-1; i>0; i--)
        {
            mins[i] = min(mins[i*2], mins[i*2+1]);
        }
    }

    int _getMin(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
            return INF;
        if(l==minL&&r==maxR)
            return mins[_i];
        int mid = (minL+maxR)/2;
        return min(_getMin(l, min(r, mid), minL, mid, _i*2),
                   _getMin(max(l,mid+1), r, mid+1, maxR, _i*2+1));

    }

    int getMin(int l, int r)
    {
        return _getMin(l, r, 1, _size, 1);
    }


};


int main()
{
    int _q;
    scanf("%d", &_q);
    for(int _i = 0; _i<_q; _i++)
    {
        int n;
        int tmp1, tmp2;
        scanf("%d", &n);
        SegmentTree st(10000);
        vector<int> countOfGuardians(10000,0);
        b.clear();
        a.clear();
        for(int i = 0; i<n; i++)
        {
            scanf("%d%d", &tmp1, &tmp2);
            a.push_back(make_pair(tmp1,1));
            a.push_back(make_pair(tmp2,-1));
            b.push_back(make_pair(tmp1+1,tmp2));
        }
        a.push_back(make_pair(100500, 0));
        sort(a.begin(), a.end());
        for(int i = 0, j = 0, current = 0; i<10000; i++)
        {
            while(a[j].first<=i)
            {
                current+=a[j++].second;
            }
            countOfGuardians[i] = current;
        }
        st.build(10000,countOfGuardians);
        bool ans = st.getMin(1,10000);
        for(int i = 0; i<b.size(); i++)
            ans &= (st.getMin(b[i].first, b[i].second)==1);

        if(ans)
            printf("Accepted\n");
        else
            printf("Wrong Answer\n");
    }
    return 0;
}
