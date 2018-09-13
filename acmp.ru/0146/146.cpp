#include<iostream>
#include<cassert>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;

int BASE = 1000*1000*1000;
int LEN_OF_BASE = 9;

struct UInt
{
    vector<int> digits;

    UInt(long long source = 0)
    {
        while(source)
        {
            digits.push_back(int(source%BASE));
            source/=BASE;
        }
    }

    UInt(const string & source)
    {
        if(source != "0")
        {
            digits.resize((source.size()-1)/LEN_OF_BASE + 1, 0);

            for(int i = 0; i<(int)source.size(); i+=LEN_OF_BASE)
            {
                int carry = 0;
                for(int j = min(LEN_OF_BASE, (int)source.size() - i) - 1 ; j>=0; j--)
                {
                    carry*=10;
                    carry+=source[source.size() - (i+j) - 1] - '0';
                }
                digits[i/LEN_OF_BASE] = carry;
            }
        }

    }

    int size() const
    {
        return (int)digits.size();
    }

    int & operator [](int i)
    {
        assert(i>=0);
        if(i>=(int)digits.size())
            digits.resize(i+1, 0);
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

ostream & operator << (ostream & outStream, const UInt & toWrite)
{
    if(toWrite.size())
    {
        outStream << toWrite(toWrite.size() - 1);

        outStream.fill('0');
        for(int i = toWrite.size() - 2; i>=0; i--)
            outStream << setw(LEN_OF_BASE) << toWrite(i);
    }
    else
    {
        outStream << 0;
    }
    return outStream;
}

istream & operator >> (istream & inStream, UInt & toRead)
{
    string s;
    inStream >> s;
    toRead = UInt(s);
    return inStream;
}

UInt operator * (const UInt & lOp, const UInt & rOp)
{
    UInt res;
    if(lOp.size()&&rOp.size())
    {
        for(int i = 0; i<lOp.size(); i++)
        {
            long long carry = 0;
            for(int j = 0; j<rOp.size()||carry; j++)
            {
                carry+=lOp(i)*1LL*rOp(j) + res[i+j];
                res[i+j] = int(carry%BASE);
                carry/=BASE;
            }
        }
    }

    return res;

}

bool operator < (const UInt & lOp, const UInt & rOp)
{
    if(lOp.size()!=rOp.size())
        return lOp.size() < rOp.size();

    for(int i = lOp.size() - 1; i>=0; i--)
        if(lOp(i)!=rOp(i))
            return lOp(i)<rOp(i);

    return 0;
}

UInt sqrt(const UInt & toFind)
{
    UInt res;

    int lenOfSqrt = (toFind.size() - 1)/2 + 1;
    for(int i = lenOfSqrt - 1; i>=0; i--)
    {
        int l = 0, r = BASE;
        while(l<r-1)
        {
            res[i] = (l+r)/2;
            if(toFind < (res*res))
                r = res[i];
            else
                l = res[i];
        }
        res[i] = l;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    UInt a,b;

    cin >> a;
    cout << sqrt(a);


    return 0;
}
