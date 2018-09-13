#include<iostream>
#include<vector>

using namespace std;

const int INF = 2000000001;

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
    void build(int n)
    {
        for(int i = 0; i<n; i++)
        {
            cin >> mins[i+_size];
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
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    SegmentTree st(n);
    st.build(n);

    for(int i = 0; i<n-k+1; i++)
    {
        cout << st.getMin(i+1, i+k) << ' ';
    }
    return 0;
}
