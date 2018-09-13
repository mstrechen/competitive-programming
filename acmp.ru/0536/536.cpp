#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cassert>
#include<algorithm>

using namespace std;

struct UInt
{
    vector<int> _digits;
    int _base;
    int _lenOfBase;

    UInt(long long n = 0, int base = 1000000000):_base(base)
    {
       assert(n>=0);
       assert(base>=10);

       while(n)
       {
           _digits.push_back(int(n%_base));
           n/=_base;
       }
       _lenOfBase = -1;
       while(base)
       {
           assert((base>=10)^(base%10!=0));
           assert(base%10<2);
           _lenOfBase++;
           base/=10;
       }
    }

    int size() const
    {
        return _digits.size();
    }
    int operator [](int i) const
    {
        if(i<0||_digits.size()<=i)
            return 0;
        return _digits[i];
    }
    int base() const
    {
        return _base;
    }
    int lenOfBase() const
    {
        return _lenOfBase;
    }


    void push_digit(int num)
    {
        _digits.push_back(num);
    }
    void pop_digit()
    {
        _digits.pop_back();
    }

    void printWithPrecision(int len) const
    {
        long long mod = 1;
        int j = 0;
        string buffer;
        for(int i = 0; i<len; i++)
        {
            buffer.push_back('0' + (this->_digits[j] %(mod*10))/mod);
            if(mod==base())
            {
                mod = 1;
                j++;
            }
            else
                mod*=10;
        }
        while(buffer.size()&&(buffer.back()=='0'))
            buffer.pop_back();
        reverse(buffer.begin(),buffer.end());
        if(buffer.size())
            cout << buffer;
        else
            cout << '0';

    }
};

UInt operator + (const UInt & a, const UInt & b)
{
    assert(a.base()==b.base());
    int carry = 0;
    UInt res(0,a.base());

    for(int i = 0; i<a.size()||i<b.size()||carry; i++)
    {
        carry+=a[i]+b[i];
        res.push_digit(carry%res.base());
        carry/=res.base();
    }
    return move(res);
}

std::ostream& operator << (std::ostream &out, const UInt &value)
{
    if(value.size())
    {
        out << value[value.size()-1];
        out << setfill('0');

        for(int i = value.size()-2; i>=0; i--)
        {
            out.width(value.lenOfBase());
            out << value[i];
        }

    }
    else
        out.put('0');
    return out;
}

std::istream& operator >> (std::istream &in, UInt &value)
{
    string bufString;
    in >> bufString;

    int buffer = 0;
    int j = 1;
    for(int i = (int)bufString.size()-1; i>=0; i--)
    {
        buffer+=(bufString[i]-'0')*j;
        j*=10;
        if(j==value.base())
        {
            j = 1;
            value.push_digit(buffer);
            buffer = 0;
        }
    }
    if(buffer)
        value.push_digit(buffer);


    return in;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int len,maxValue, lenOfAnswer;
    cin >> len >> maxValue >> lenOfAnswer;

    string sToFind;
    cin >> sToFind;

    vector<UInt> dp(len+20,UInt(0));
    dp[len] = UInt(1);


    for(int i = len-1; i>=0; i--)
    {
        int buffer = 0;
        if(sToFind[i]=='0')
            dp[i] = dp[i+1];
        else
            for(int j = 0; i+j<len && buffer<=maxValue; j++)
            {
                buffer*=10;
                buffer+=sToFind[i+j]-'0';
                if(buffer<=maxValue)
                    dp[i] = dp[i] + dp[i+j+1];
            }
    }

    dp[0].printWithPrecision(lenOfAnswer);

    return 0;
}
