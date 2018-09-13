#include<iostream>
#include<string>
#include<vector>

using namespace std;

unsigned int MOD = 1000*1000*1000 + 7;

template<typename T>
struct FourdimensionalArray
{
    T * _ptr;
    int a, b, c, d;

    FourdimensionalArray() : _ptr(nullptr)
    {
    }
    FourdimensionalArray(int a, int b, int c, int d) : a(a), b(b), c(c), d(d)
    {
        _ptr = new T[a*b*c*d];
    }

    FourdimensionalArray(int a, int b, int c, int d, const T & val) : a(a), b(b), c(c), d(d)
    {
        _ptr = new T[a*b*c*d];

        for(int i = a*b*c*d - 1; i>=0; i--)
            _ptr[i] =  val;
    }

    void operator = (const FourdimensionalArray & tmp) = delete;
    FourdimensionalArray(const FourdimensionalArray & tmp) = delete;

    ~FourdimensionalArray()
    {
        delete [] _ptr;
    }

    T & operator ()(int _i, int _j, int _k, int _l)
    {
        return _ptr[_i * b*c*d + _j * c*d + _k * d + _l];
    }

    void assign(int _a, int _b, int _c, int _d)
    {
        delete [] _ptr;

        a = _a, b = _b, c = _c, d = _d;
        _ptr = _ptr = new T[a*b*c*d];
    }
    void assign(int _a, int _b, int _c, int _d, const T & val)
    {
        delete [] _ptr;

        a = _a, b = _b, c = _c, d = _d;
        _ptr = new T[a*b*c*d];

        for(int i = a*b*c*d - 1; i>=0; i--)
            _ptr[i] =  val;
    }

};

struct Solution
{
    vector<int> digits;
    mutable FourdimensionalArray<unsigned int> memoized;
    mutable FourdimensionalArray<bool> used;

    Solution(const string & s)
    {
        digits.assign(s.size(), 0);
        for(int i = 0; i<(int)s.size(); i++)
            digits[i] = s[i] - '0';
        memoized.assign(s.size(), 10, 10, 2, 0);
            used.assign(s.size(), 10, 10, 2, false);
    }

    unsigned int getSmall(int pos, int dA, int dB, int carry) const
    {
        if(used(pos, dA, dB, carry))
            return memoized(pos, dA, dB, carry);

        used(pos, dA, dB, carry) = true;

        if(pos == 0)
        {
            if(dA == 0 || dB == 0)
                return memoized(pos, dA, dB, carry) = 0;

            return memoized(pos, dA, dB, carry) = (dA + dB + carry == digits[pos]);
        }

        if((dA + dB + carry)%10 != digits[pos])
            return memoized(pos, dA, dB, carry) = 0;



        int carryNew = (dA + dB + carry)/10;

        unsigned int ans = 0;

        for(int dAnew = 0; dAnew < 10; dAnew++)
        if(dAnew!=dA)
            for(int dBnew = 0; dBnew < 10; dBnew++)
            if(dBnew!=dB)
            {
                ans += getSmall(pos-1, dAnew, dBnew, carryNew);
                ans %= MOD;
            }

        return memoized(pos, dA, dB, carry) = ans;
    }

    unsigned int getAnswer() const
    {
        unsigned int ans = 0;

        for(int digitA = 0; digitA<10; digitA++)
            for(int digitB = 0; digitB<10; digitB++)
            {
                ans += getSmall((int)digits.size() - 1, digitA, digitB, 0);
                ans %= MOD;
            }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if(s.size() == 1)
    {
        cout << (s[0] - '0') - 1;
        return 0;
    }

    Solution solution(s);

    cout << solution.getAnswer();

    return 0;
}
