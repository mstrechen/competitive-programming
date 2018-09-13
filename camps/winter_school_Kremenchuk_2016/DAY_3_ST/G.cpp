#include<iostream>
#include<vector>
#include<functional>

using namespace std;

long long MOD = 1000000000 + 7;

struct matrix2x2
{
    long long a00,a01,a10,a11;
    matrix2x2(int a00 = 1,int a01 = 0,int a10 = 0,int a11 = 1) : a00(a00),
                                                                 a01(a01),
                                                                 a10(a10),
                                                                 a11(a11){}
};

struct vector2
{
    int a0, a1;
    vector2(int a0 = 0, int a1 = 0) : a0(a0),a1(a1){};
};

matrix2x2 operator * (const matrix2x2 & a, const matrix2x2 & b)
{
    matrix2x2 res;

    res.a00 = (a.a00*b.a00 + a.a01*b.a10)%MOD;
    res.a01 = (a.a00*b.a01 + a.a01*b.a11)%MOD;
    res.a10 = (a.a10*b.a00 + a.a11*b.a10)%MOD;
    res.a11 = (a.a10*b.a01 + a.a11*b.a11)%MOD;


    return res;
}


vector2 operator * (const matrix2x2 & a, vector2 & b)
{
    vector2 res;
    res.a0 = (a.a00*b.a0 + a.a01*b.a1)%MOD;
    res.a1 = (a.a10*b.a0 + a.a11*b.a1)%MOD;
    return res;
}


matrix2x2 multiply_1_2(const matrix2x2 & a, const matrix2x2 & b)
{
    return a*b;
}
matrix2x2 multiply_2_1(const matrix2x2 & a, const matrix2x2 & b)
{
    return b*a;
}




istream & operator >> (istream & inStream, matrix2x2 & toRead)
{
    inStream >> toRead.a00 >> toRead.a01 >> toRead.a10 >> toRead.a11;

    return inStream;
}

istream & operator >> (istream & inStream, vector2 & toRead)
{
    inStream >> toRead.a0 >> toRead.a1;

    return inStream;
}

ostream & operator << (ostream & outStream, const vector2 & toWrite)
{
    outStream << toWrite.a0 << ' ' << toWrite.a1;
}


struct SegmentTree
{
    vector<matrix2x2> maxes;
    int _size;

    function<matrix2x2(matrix2x2, matrix2x2)> f;

    SegmentTree(int size, istream & in, function<matrix2x2(matrix2x2, matrix2x2)> multiplyOrder)
    {
        f = multiplyOrder;
        _size = 1;

        while(_size<size)
            _size*=2;

        maxes.assign(_size*2,matrix2x2() );

        for(int i = 0; i<size; i++)
            in >> maxes[i+_size];

        for(int i = _size-1; i>0; i--)
            maxes[i] = f(maxes[i*2],maxes[i*2+1]);
    }

    SegmentTree(int size = 0, function<matrix2x2(matrix2x2, matrix2x2)> multiplyOrder = multiply_1_2)
    {
        _size = 1;

        while(_size<size)
            _size*=2;

        maxes.assign(_size*2, matrix2x2());
    }

    SegmentTree(SegmentTree & source, function<matrix2x2(matrix2x2, matrix2x2)> multiplyOrder = multiply_1_2)
    {
        _size = source._size;
        maxes = source.maxes;
        f = multiplyOrder;
        for(int i = _size-1; i>0; i--)
            maxes[i] = f(maxes[i*2],maxes[i*2+1]);
    }



    matrix2x2 _get(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
            return matrix2x2();
        if(l==minL && r == maxR)
            return maxes[_i];

        int mid = (minL+maxR)/2;

        return f(_get(l,min(r,mid), minL, mid, _i*2),_get(max(mid+1, l), r, mid+1, maxR, _i*2 + 1));
    }

    matrix2x2 get(int l, int r)
    {
        return _get(l,r, 1, _size, 1);
    }
};





int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    SegmentTree ST(n,cin, multiply_2_1);

    SegmentTree ST_reversed(ST, multiply_1_2);

    vector2 tmp;
    while(q--)
    {

        cin >> tmp;
        int l, r;
        cin >> l >> r;

        if(l<r)
        {
            tmp = ST.get(l,r) * tmp;
        }
        else
        {
            tmp = ST_reversed.get(r,l) * tmp;
        }

        cout << tmp <<'\n';
    }

    return 0;
}
