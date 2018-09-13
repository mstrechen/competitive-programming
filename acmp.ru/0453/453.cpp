#include<iostream>
#include<cassert>
#include<vector>
#include<climits>
#include<iomanip>
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

    UInt(vector<int> && source)
    {
        digits.swap(source);
        reverse(digits.begin(), digits.end());
        for(int i = digits.size() - 1; i>=0&&digits[i]==0; i--)
            digits.pop_back();
    }

    int size() const
    {
        return (int)digits.size();
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

    bool isZero() const
    {
        return this->size() == 0;
    }

};

UInt operator * (const UInt & lOp, long long rOp)
{
    if(rOp == 0)
        return UInt(0);

    UInt res;

    long long carry = 0;

    assert(rOp*BASE < LLONG_MAX);

    for(int i = 0; i<lOp.size()||carry; i++)
    {
        carry+=lOp(i)*rOp;
        res[i] = int(carry%BASE);
        carry/=BASE;
    }

    return res;
}

ostream & operator << (ostream & outStream, const UInt & toWrite)
{
    if(toWrite.size())
    {
        cout << toWrite(toWrite.size() - 1);
        outStream.fill('0');

        for(int i = toWrite.size()-2; i>=0; i--)
            outStream << setw(LEN_OF_BASE) << toWrite(i);

    }
    else
    {
        cout << 0;
    }

    return outStream;
}

bool operator < (const UInt & lOp, const UInt & rOp)
{
    if(lOp.size()!=rOp.size())
        return lOp.size() < rOp.size();

    for(int i = lOp.size()-1; i>=0; i--)
        if(lOp(i)!=rOp(i))
            return lOp(i)<rOp(i);

    return 0;
}

void operator <<=(UInt & lOp, int rOp)
{
    assert(rOp>=0);
    for(int i = lOp.size()+rOp-1; i>=rOp; i--)
        lOp[i] = lOp[i-rOp];
    for(int i = rOp-1; i>=0; i--)
        lOp[i] = 0;
}

void operator -= (UInt & lOp, const UInt & rOp)
{
    int carry = 0;
    for(int i = 0; i<rOp.size()||carry; i++)
    {
        carry += lOp[i] - rOp(i);
        if(carry>=0)
        {
            lOp[i] = carry;
            carry = 0;
        }
        else
        {
            lOp[i] = carry + BASE;
            carry = -1;
        }
    }
    for(int i = lOp.size() - 1; i>=0 && lOp[i] == 0; i--)
        lOp.digits.pop_back();

}

UInt operator + (const UInt & lOp, const UInt & rOp)
{
    UInt res;

    int carry = 0;
    for(int i = 0; i<lOp.size()||i<rOp.size()||carry; i++)
    {
        carry+=lOp(i)+rOp(i);
        res[i] = carry%BASE;
        carry/=BASE;
    }
    return res;
}

UInt operator % (const UInt & lOp, const UInt & rOp)
{
    assert(!rOp.isZero());

    if(lOp < rOp)
        return lOp;

    UInt carry;

    //vector<int> res;

    for(int i = lOp.size() - rOp.size(); i<lOp.size(); i++)
        carry[i - lOp.size() + rOp.size()] = lOp(i);

    for(int i = lOp.size() - rOp.size(); i>0; i--)
    {
        int l = 0, r = BASE;
        while(l+1<r)
        {
            int mid = (l+r)/2;
            if(carry < rOp*mid)
                r = mid;
            else
                l = mid;
        }
        //res.push_back(l);
        carry-= rOp * l;
        carry <<= 1;
        carry[0] = lOp(i-1);
    }

    int l = 0, r = BASE;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(carry < rOp*mid)
            r = mid;
        else
            l = mid;
    }
    //res.push_back(l);
    carry-= rOp * l;

    return carry;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;

    UInt res, twoInPow = 1, tenInPow = 1;

    for(int i = 0; i<n; i++)
    {
        twoInPow = twoInPow*2;

        res = res + tenInPow;
        if(!(res%twoInPow).isZero())
            res = res + tenInPow;

        tenInPow = tenInPow*10;
    }

    cout << res;

    return 0;
}
