#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

const double eps = 1e-9;

struct UInt
{
    vector<int> digits;
    int BASE;

    UInt(int source = 0, int base = 1000000000):BASE(base)
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

    int & operator [](int i)
    {
        assert(i>=0);
        if(i>=digits.size())
            digits.resize(i+1, 0);
        return digits[i];
    }
    int operator ()(int i) const
    {
        assert(i>=0);
        if(i>=digits.size())
            return 0;
        return digits[i];
    }
};

ostream & operator << (ostream & outStream, const UInt & toWrite)
{
    if(toWrite.size())
    {
        outStream << toWrite(toWrite.size() - 1);

        int len = toWrite.lenOfBase();

        outStream.fill('0');
        for(int i = toWrite.size()-2; i>=0; i--)
            outStream << setw(len) << toWrite(i);
    }
    else
        outStream << 0;

    return outStream;
}

void operator += (UInt & lOp, const UInt & rOp)
{
    assert(lOp.BASE == rOp.BASE);

    int carry = 0;
    for(int i = 0; i<rOp.size()||carry; i++)
    {
        lOp[i] += carry + rOp(i);
        carry = lOp[i]/lOp.BASE;
        lOp[i]%=lOp.BASE;
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

	int n,k;

	cin >> k >> n;

    vector<UInt> dp(n+1, 0);

    dp[0] = 1;

    for(int i = 1; i<=n; i++)
    {
        for(int j = max(0, i-k); j<i; j++)
            dp[i]+=dp[j];
    }

    cout << dp[n];

	return 0;
}
