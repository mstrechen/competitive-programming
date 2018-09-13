#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int oo = 1000*1000*1000;

struct SegmentTree
{
    vector<int> add, mins;
    int _size;

    SegmentTree(int size)
    {
        size++;
        _size = size;
        while(_size & (_size - 1))
            _size &= _size - 1;

        if(size!=_size)
            _size*=2;

        add.assign(_size*2, 0);
        mins.assign(_size*2, oo);

        for(int i = 0; i<size; i++)
            mins[i+_size] = 0;

        for(int i = _size-1; i>0; i--)
            mins[i] = min(mins[i*2], mins[i*2+1]);
    }

    int _change(int l, int r, int minL, int maxR, int _i, int val)
    {
        if(l == minL && r == maxR)
        {
            add[_i]+=val;
            return mins[_i] + add[_i];
        }
        if(l>r)
            return mins[_i] + add[_i];

        int mid = (minL+maxR)/2;

        return (mins[_i] = min(_change(l, min(r, mid), minL, mid, _i*2, val),
                              _change(max(mid+1,l), r, mid+1, maxR , _i*2 + 1, val)) )
                        + add[_i];
    }



    int _get(int l, int r, int minL, int maxR, int _i)
    {
        if(l==minL && r==maxR)
        {
            return mins[_i] + add[_i];
        }
        if(l>r)
            return +oo;

        int mid = (minL+maxR)/2;

        return min(_get(l, min(r,mid), minL, mid, _i*2),
                   _get(max(l,mid+1), r, mid+1, maxR, _i*2 + 1)) + add[_i];
    }

    int get(int l, int r)
    {
        l++;
        r++;
        return _get(l, r, 1, _size, 1);
    }

    void change(int l, int r, int val = 1)
    {
        l++;
        r++;
        _change(l, r, 1, _size, 1, val);
    }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n;
	cin >> n;

	SegmentTree ST(n);
	vector<int> numbers(n+1,0);

	for(int i = 0; i<n; i++)
    {
        int num, type;
        cin >> num >> type;
        if(type)
        {
            cin >> numbers[num];
            ST.change(num, n);

        }
        else
        {
            ST.change(num, n,-1);
        }

        int l = 0, r = n+1;
        int mm = ST.get(0,n);
        while(l+1<r)
        {
            int mid = (l+r)/2;
            if(ST.get(mid, n) > mm)
                r = mid;
            else
                l = mid;
        }

        if(l == n)
        {
            cout << -1 << '\n';
        }
        else
        {
            r = n+1;
            mm = ST.get(n,n);


            while(l+1<r)
            {
                int mid = (l+r)/2;
                if(ST.get(mid, n) < mm)
                    l = mid;
                else
                    r = mid;
            }
            cout << numbers[l+1] << '\n';
        }

    }


	return 0;
}
