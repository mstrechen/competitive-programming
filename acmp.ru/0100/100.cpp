#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>
#include<iomanip>
#include<fstream>

using namespace std;

const double eps = 1e-9;

struct UInt
{
    vector<long long> digits;
    long long BASE;

    UInt (int source = 0, long long base = 1000000000000000000LL):BASE(base)
    {
        assert(source>=0);
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

    long long & operator [](int _i)
    {
        assert(_i>=0);
        if(_i>=(int)digits.size())
            digits.resize(_i+1,0);
        return digits[_i];
    }
    long long operator ()(int _i) const
    {
        assert(_i>=0);
        if(_i>=(int)digits.size())
            return 0;
        return digits[_i];
    }

};


void operator += (UInt & lOp, const UInt & rOp)
{
    assert(lOp.BASE == rOp.BASE);

    int carry = 0;
    for(int i = 0; i<lOp.size()||i<rOp.size()||carry; i++)
    {
        lOp[i]+= rOp(i) + carry;
        carry = lOp[i]/lOp.BASE;
        lOp[i]%=lOp.BASE;
    }
}

ostream & operator << (ostream & outStream, const UInt & toPrint)
{
    if(toPrint.size())
    {
        outStream << toPrint(toPrint.size()-1);

        outStream.fill('0');

        int len = toPrint.lenOfBase();

        for(int i = toPrint.size()-2; i>=0; i--)
            outStream<< setw(len) << toPrint(i);

    }
    else
    {
        outStream << 0;
    }
    return outStream;
}

UInt memorized[51][1000];
bool mem_used [51][1000];

UInt dp(int len, int deltaSumm)
{
    if(mem_used[len][deltaSumm])
        return memorized[len][deltaSumm];

    mem_used[len][deltaSumm] = true;

    if(len==0)
        return memorized[len][deltaSumm] = UInt(deltaSumm == 500);

    for(int i = 0; i<10; i++)
        for(int j = 0; j<10; j++)
            memorized[len][deltaSumm] += dp(len-1, deltaSumm+i-j);
    return memorized[len][deltaSumm];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int lenOfNum;

    ofstream c_out("precalc.cpp");

    for(int i = 1; i<=50; i++)
        c_out << "prec[" << i << "] = " << '"' << dp(i, 500) << '"' << ";\n";




    return 0;
}
