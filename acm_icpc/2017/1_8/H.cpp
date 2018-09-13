#include<stdio.h>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

struct SegmentTree
{
    int size{};
    vector<long long> a{};

    SegmentTree(int n)
    {
        if(n&(n-1))
        {
            while(n&(n-1))
                n&=(n-1);
            n*=2;
        }
        size = n;
        a.assign(size*2, 0);
    }

    void _set(int pos, int minL, int maxR, int _i, long long val)
    {
        if(pos < minL || maxR < pos)
            return;
        a[_i] += val;
        if(minL == maxR)
            return;

        int mid = (minL+maxR)/2;
        if(pos <= mid)
            _set(pos, minL, mid, _i*2, val);
        else
            _set(pos, mid+1, maxR, _i*2+1, val);
    }
    void set(int pos, long long val)
    {
        _set(pos, 1, size, 1, val);
    }

    long long _get(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
            return 0;
        if(l == minL && r == maxR)
            return a[_i];

        int mid = (minL+maxR)/2;
        return _get(l, min(r, mid), minL, mid, _i*2)+
               _get(max(l, mid+1), r, mid+1, maxR, _i*2+1);

    }

    long long get(int l, int r)
    {
        return _get(max(l, 1), r, 1, size, 1);
    }


    int getVal(long long k)
    {
        int l = 1, r = size;
        int _i = 1;

        while(l!=r)
        {
            int mid = (l+r)/2;
            if(a[_i*2+1] <= k)
            {
                k -= a[_i*2+1];
                _i*=2;
                r = mid;
            }
            else
            {
                _i*=2;
                _i++;
                l = mid+1;
            }
        }
        return l;
    }
};

struct event
{
    int x;
    long long cnt, money;
};

bool operator < (const event & a, const event & b)
{
    return a.x < b.x;
}

struct Mountain
{
    const int sz = 1000001;
    vector<event> e1, e2, e;
    SegmentTree MONEY{sz}, TOSELL{sz};

    Mountain(int n, int m) : e1(n), e2(m)
    {
        e.resize(n+m);
    }

    long long getMaxAns(long long p)
    {
        long long maxAns = 0;
        merge(e1.begin(), e1.end(), e2.begin(), e2.end(), e.begin());


        long long cnt = 0;

        for(auto & i : e)
        {
            long long currentAns = -p*i.x;
            if(i.money == 0)
            {
                cnt += i.cnt;
            }
            else
            {
                int POS = i.money;
                MONEY.set(POS, i.cnt*i.money);
                TOSELL.set(POS, i.cnt);
            }


            int pos = TOSELL.getVal(cnt);
            long long canBeSelled = TOSELL.get(pos+1, sz);

            currentAns += MONEY.get(pos+1, sz);

            long long toSell = TOSELL.get(pos,pos);

            currentAns += pos*min(cnt-canBeSelled, toSell);

            maxAns = max(maxAns, currentAns);
        }
        return maxAns;
    }
};

char TMP;

inline void READ(int & a)
{
    a = 0;
    do
    {
        TMP = getchar();
    }
    while(TMP < '0' || TMP > '9');

    do
    {
        a*=10;
        a+=TMP-'0';
        TMP = getchar();
    }
    while(TMP >= '0' && TMP <= '9');
}

inline void READLL(long long & a)
{
    a = 0;
    do
    {
        TMP = getchar();
    }
    while(TMP < '0' || TMP > '9');

    do
    {
        a*=10;
        a+=TMP-'0';
        TMP = getchar();
    }
    while(TMP >= '0' && TMP <= '9');
}


int main()
{
    int n, m, p;
    READ(n);
    READ(m);
    READ(p);


    Mountain M(n, m);

    for(int i = 0; i<n; i++)
    {
        READ(M.e1[i].x);
        READLL(M.e1[i].cnt);
    }
    for(int i = 0; i<m; i++)
    {
        READ(M.e2[i].x);
        READLL(M.e2[i].cnt);
        READLL(M.e2[i].money);
    }


    printf("%lld", M.getMaxAns(p));


    return 0;
}

