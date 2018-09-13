#include<iostream>
#include<vector>
#include<cassert>
#include<iomanip>
#include<cmath>
#include<algorithm>

using namespace std;

const double eps = 1e-9;

struct UInt
{
    vector<int> digits;
    int BASE;

    UInt(int source = 0, int base = 10000):BASE(base)
    {
        while(source)
        {
            digits.push_back(source%base);
            source/=base;
        }
    }

    int size() const
    {
        return digits.size();
    }
    int lenOfBase() const
    {
        return (int)log10(BASE+eps);
    }

    int & operator [] (int _i)
    {
        assert(_i>=0);
        if(_i>=(int)digits.size())
        {
            digits.resize(_i+1,0);
        }
        return digits[_i];
    }

    int operator () (int _i) const
    {
        assert(_i>=0);
        if(_i>=(int)digits.size())
            return 0;
        return digits[_i];
    }



};

ostream & operator << (ostream & outStream, const UInt & toWrite)
{
    if(toWrite.size())
    {
        outStream << toWrite(toWrite.size()-1);
        outStream.fill('0');

        int len = toWrite.lenOfBase();

        for(int i  = toWrite.size()-2; i>=0; i--)
        {
            outStream << setw(len) << toWrite(i);
        }
    }
    else
        outStream << '0';
    return outStream;
}

UInt operator + (const UInt & lOp, const UInt & rOp)
{
    assert(lOp.BASE==rOp.BASE);

    UInt res(0, lOp.BASE);

    int carry = 0;

    for(int i = 0; i<lOp.size()||i<rOp.size()||carry; i++)
    {
        res[i] = lOp(i)+rOp(i)+carry;
        carry = res[i]/res.BASE;
        res[i] %= res.BASE;
    }

    return move(res);
}
void operator += (UInt & lOp, const UInt & rOp)
{
    assert(lOp.BASE==rOp.BASE);

    int carry = 0;

    for(int i = 0; i<lOp.size()||i<rOp.size()||carry; i++)
    {
        lOp[i]+= rOp(i)+carry;
        carry = lOp[i]/lOp.BASE;
        lOp[i] %= lOp.BASE;
    }
}

UInt operator * (const UInt & lOp, const UInt & rOp)
{
    assert(lOp.BASE == rOp.BASE);

    UInt res(0, rOp.BASE);

    int carry;

    for(int i = 0; i<lOp.size(); i++)
    {
        carry = 0;
        for(int j = 0; j<rOp.size()||carry; j++)
        {

            res[i+j]+= carry + lOp(i)*rOp(j);
            carry = res[i+j]/res.BASE;
            res[i+j]%=res.BASE;
        }
    }
    if(lOp.size()+rOp.size() && res[lOp.size()+rOp.size()-1]==0)
        res.digits.pop_back();

    return res;
}


struct matrix
{
    vector<vector<UInt> > fields;
    matrix(int _size = 0)
    {
        fields.assign(_size,vector<UInt>(_size,0) );
    }

    vector<UInt> & operator [](int i)
    {
        assert(0<=i && i<=(int)fields.size());
        return fields[i];
    }

    const vector<UInt> & operator ()(int i) const
    {
        assert(0<=i && i<=(int)fields.size());
        return fields[i];
    }

    int size() const
    {
        return fields.size();
    }
};

matrix operator * (const matrix & lOp, const matrix & rOp)
{
    assert(lOp.size() == rOp.size());

    matrix res(lOp.size());

    for(int k = 0; k<res.size(); k++)
        for(int i = 0; i<res.size(); i++)
            for(int j = 0; j<res.size(); j++)
            {
                res[i][j] +=lOp(i)[k]*rOp(k)[j];
            }
    return res;
}

matrix operator ^ (const matrix & x, int pow)
{
    assert(pow>0);

    if(pow==1)
        return x;

    if(pow%2==1)
    {
        return x*(x^(pow-1)) ;
    }

    matrix tmp = x^(pow/2);
    tmp = tmp*tmp;

    return tmp;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    matrix a(10),b(10);

    for(int i = 1; i<10; i++)
        if(i!=8)
            b[i][i] = 1;


    a[6][1] = 1;
    a[1][6] = 1;

    a[8][1] = 1;
    a[1][8] = 1;

    a[2][7] = 1;
    a[7][2] = 1;

    a[2][9] = 1;
    a[9][2] = 1;

    a[3][4] = 1;
    a[4][3] = 1;

    a[3][8] = 1;
    a[8][3] = 1;

    a[4][9] = 1;
    a[9][4] = 1;

    a[4][0] = 1;
    a[0][4] = 1;

    a[6][7] = 1;
    a[7][6] = 1;

    a[6][0] = 1;
    a[0][6] = 1;

    int n;
    cin >> n;

    if(n>1)
    {
        a = a^(n-1);
        b = b*a;
    }

    UInt ans;

    for(int i = 0; i<10; i++)
        for(int j = 0; j<10; j++)
            ans+=b[i][j];
    cout << ans;


    return 0;
}
