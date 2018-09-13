#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<cassert>

using namespace std;

const double eps = 1e-9;

struct UInt
{
    vector<int> digits;
    int BASE;

    UInt(int source = 0, int base = 1000000): BASE(base)
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

    int & operator [](int i)
    {
        assert(i>=0);
        if(i>=(int)digits.size())
            digits.resize(i+1,0);
        return digits[i];
    }
    int operator ()(int i) const
    {
        assert(i>=0);
        if(i>=(int)digits.size())
            return 0;
        return digits[i];
    }

};

ostream & operator << (ostream & outStream, UInt toWrite)
{
    if(toWrite.size())
    {
        outStream << toWrite[toWrite.size()-1];

        outStream.fill('0');

        int len = toWrite.lenOfBase();

        for(int i = toWrite.size() -2; i>=0; i--)
            outStream << setw(len) << toWrite[i];
    }
    else
    {
        outStream << 0;
    }
    return outStream;
}

void operator *= (UInt & lOp, const int rOp)
{
    int carry = 0;

    for(int i = 0; i<lOp.size()||carry; i++)
    {
        lOp[i]*=rOp;
        lOp[i]+=carry;
        carry = lOp[i]/lOp.BASE;
        lOp[i]%=lOp.BASE;
    }
}

UInt operator + (const UInt & lOp, const UInt & rOp)
{
    assert(lOp.BASE==rOp.BASE);
    UInt res(0, lOp.BASE);

    int carry = 0;

    for(int i = 0; i<lOp.size()||i<rOp.size()||carry; i++)
    {
        res[i] = lOp(i) + rOp(i) + carry;
        carry = res[i]/res.BASE;
        res[i]%=res.BASE;
    }
    return move(res);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    if(n==1)
    {
        cout << 0;
        return 0;
    }
    UInt prev_offset_1 = 1, prev_offset_2 = 0;
    UInt tmp;

    for(int i = 3; i<=n; i++)
    {
        tmp = prev_offset_1 + prev_offset_2;
        tmp*=i-1;
        prev_offset_2 = prev_offset_1;
        prev_offset_1 = tmp;
    }
    cout << prev_offset_1;


    return 0;
}
