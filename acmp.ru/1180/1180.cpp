#include<iostream>
#include<vector>

using namespace std;

const int INF = -2000000001;

struct SegmentTree
{
    vector<int> maxs;
    int _size;

    SegmentTree(int a)
    {
        _size = 1;
        while(_size<a)
            _size*=2;
        maxs = vector<int>(_size*2, INF);
    }
    void build(int n)
    {
        for(int i = 0; i<n; i++)
        {
            cin >> maxs[i+_size];
        }
        for(int i = _size-1; i>0; i--)
        {
            maxs[i] = max(maxs[i*2], maxs[i*2+1]);
        }
    }

    int _getmax(int l, int r, int maxL, int maxR, int _i)
    {
        if(l>r)
            return INF;
        if(l==maxL&&r==maxR)
            return maxs[_i];
        int mid = (maxL+maxR)/2;
        return max(_getmax(l, min(r, mid), maxL, mid, _i*2),
                   _getmax(max(l,mid+1), r, mid+1, maxR, _i*2+1));

    }

    int getmax(int l, int r)
    {
        return _getmax(l, r, 1, _size, 1);
    }


};


int main()
{
    ios::sync_with_stdio(false);

    int n,k;

    int tmp1, tmp2;

    cin >> n;

    SegmentTree st(n);
    st.build(n);

    cin >> k;

    for(int i = 0; i<k; i++)
    {
        cin >> tmp1 >> tmp2;
        cout << st.getmax(tmp1,tmp2) << ' ';
    }

    return 0;
}
