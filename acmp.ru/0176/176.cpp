#include<iostream>
#include<vector>
#include<cassert>
#include<iomanip>

using namespace std;

const int BASE = 1000*1000*1000;
const int BASE_LEN = 3+3+3;


struct UInt
{
    vector<int> digits;

    UInt(int source = 0)
    {
        while(source)
        {
            digits.push_back(source%BASE);
            source/=BASE;
        }
    }

    int size() const
    {
        return digits.size();
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

        for(int i = toWrite.size() -2; i>=0; i--)
            outStream << setw(BASE_LEN) << toWrite[i];
    }
    else
    {
        outStream << 0;
    }
    return outStream;
}


UInt operator + (const UInt & lOp, const UInt & rOp)
{
    UInt res(0);

    int carry = 0;

    for(int i = 0; i<lOp.size()||i<rOp.size()||carry; i++)
    {
        res[i] = lOp(i) + rOp(i) + carry;
        carry = res[i]/BASE;
        res[i]%=BASE;
    }
    return move(res);
}


struct dpUnit
{
    UInt all, reached;
};

dpUnit operator + (dpUnit & left, dpUnit & right)
{
    return {left.all + right.all, left.reached + right.reached};
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int len, depth;

    cin >> len >> depth;

    len*=2;

    vector<vector<dpUnit> > dp(len+1, vector<dpUnit>(depth+1));

    dp[0][0] = {1,0};

    for(int curLen = 1; curLen <= len; curLen++)
    {
        dp[curLen][0] = dp[curLen-1][1];
        for(int curDepth = 1; curDepth<depth; curDepth++)
            dp[curLen][curDepth] = dp[curLen-1][curDepth-1] + dp[curLen-1][curDepth+1];

        dp[curLen][depth]= {dp[curLen-1][depth-1].all,dp[curLen-1][depth-1].all};
    }

    cout << dp[len][0].reached;

    return 0;
}
