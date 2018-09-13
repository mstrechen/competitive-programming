#include<iostream>
#include<vector>
#include<cassert>
#include<iomanip>
#include<cmath>

using namespace std;

const double eps = 1e-9;

struct UInt
{
    int BASE;
    vector<int> digits;

    UInt(int source = 0, int base = 10000000) : BASE(base)
    {
        while(source)
        {
            digits.push_back(source%base);
            source/=base;
        }
    }

    int & operator [] (int _i)
    {
        assert(_i>=0);

        if(_i>=digits.size())
            digits.resize(_i+1, 0);
        return digits[_i];
    }

    int size() const
    {
        return digits.size();
    }

    int & at(int _i)
    {
        assert(_i>=0);

        if(_i>=digits.size())
            digits.resize(_i+1, 0);
        return digits[_i];
    }

    void operator *= (int mul)
    {
        int carry = 0;
        for(int i = 0; i<(int)digits.size() || carry; i++)
        {
            this->at(i)*=mul;
            this->at(i) += carry;
            carry = this->at(i) / BASE;
            this->at(i)%=BASE;
        }
    }

    void operator -=(int dec)
    {
        int carry = dec;
        for(int i = 0; i<(int)digits.size() && carry; i++)
        {
            this->at(i)-=carry;
            if(this->at(i) < 0)
            {
                carry = 1;
                this->at(i)+=BASE;
            }
            else
                carry = 0;
        }
    }

    int getBaseLen() const
    {
        return log10(BASE+eps);
    }

};

ostream& operator << (ostream& outStream, UInt toWrite)
{
    if(toWrite.digits.size())
    {
        outStream << toWrite.digits[toWrite.size()-1];
        outStream << setfill('0');

        int lenOfFill = toWrite.getBaseLen();

        for(int i = toWrite.size()-2; i>=0; i--)
        {
            outStream.width(lenOfFill);
            outStream << toWrite[i];
        }
    }

    return outStream;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    UInt dp(2);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        dp*=3;
        dp-=2;
    }

    cout << dp;

    return 0;
}
