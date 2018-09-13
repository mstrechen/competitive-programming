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


void operator += (UInt & lOp, const UInt & rOp)
{

    int carry = 0;
    for(int i = 0; i<rOp.size()||carry; i++)
    {
        lOp[i] += carry + rOp(i);
        carry = lOp[i]/BASE;
        lOp[i]%=BASE;
    }
}



const int numOnKey[26] = {0,1,2,
                          0,1,2,
                          0,1,2,
                          0,1,2,
                          0,1,2,
                          0,1,2,3,
                          0,1,2,
                          0,1,2,3};

const int letterToKey[26] =  {0,0,0,
                              1,1,1,
                              2,2,2,
                              3,3,3,
                              4,4,4,
                              5,5,5,5,
                              6,6,6,
                              7,7,7,7};

const int countOnKey[8] = {  3,3,
                           3,3,3,
                           4,3,4};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int lenOfSource;

    cin >> lenOfSource >> s;

    vector<int> processed;

    for(auto i : s)
    {
        for(int j = 0; j<=numOnKey[i-'A']; j++)
            processed.push_back(letterToKey[i-'A']);
    }


    vector<vector<UInt> > dp(processed.size()+1, vector<UInt>(lenOfSource + 1, 0));

    dp[0][0] = 1;

    for(int pressed = 1; pressed<=(int)processed.size(); pressed++)
    {
        for(int printed = 1; printed<=lenOfSource; printed++)
        {
            dp[pressed][printed] = dp[pressed-1][printed-1];

            if(pressed>1 && processed[pressed-1] == processed[pressed-2])
            {
                dp[pressed][printed] += dp[pressed-2][printed-1];
                if(pressed>2 && processed[pressed-1] == processed[pressed-3])
                {
                    dp[pressed][printed] += dp[pressed-3][printed-1];
                    if(pressed>3 && countOnKey[processed[pressed-1] ] == 4 && processed[pressed-1] == processed[pressed-4])
                        dp[pressed][printed] += dp[pressed-4][printed-1];

                }
            }

        }
    }

    cout << dp[processed.size()][lenOfSource];

    return 0;
}
