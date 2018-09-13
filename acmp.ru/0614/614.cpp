#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<iomanip>
#include<vector>

using namespace std;

const int BASE =    1000 * 1000 * 1000;
const int BASE_LEN =   3 +    3 +    3;

struct UInt
{
    vector<int> dig;

    UInt(int a = 0)
    {
        while(a)
        {
            dig.push_back(a%BASE);
            a/=BASE;
        }
    }

    int size() const
    {
        return dig.size();
    }

    int & operator [](int i)
    {
        assert(i>=0);
        if(i>=(int)dig.size())
            dig.resize(i+1, 0);
        return dig[i];
    }

    int operator [](int i) const
    {
        assert(i>=0);
        if(i>=(int)dig.size())
            return 0;
        return dig[i];
    }

};

ostream & operator << (ostream & out, const UInt & toWrite)
{
    if(toWrite.size())
    {
        out << toWrite[toWrite.size() - 1];

        out.fill('0');

        for(int i = toWrite.size() - 2; i>=0; i--)
            out << setw(BASE_LEN) << toWrite[i];
    }
    else
    {
        out << 0;
    }

    return out;
}

UInt & operator += (UInt & left, const UInt & right)
{
    if(&left == &right)
        return left;

    int carry = 0;
    for(int i = 0; i<right.size() || carry; i++)
    {
        carry+=right[i]+left[i];
        left[i] = carry % BASE;
        carry/=BASE;
    }

    return left;
}

UInt & operator += (UInt & left, int right)
{
    assert(right<BASE);

    int carry = right;
    for(int i = 0; i<carry; i++)
    {
        carry+=left[i];
        left[i] = carry % BASE;
        carry/=BASE;
    }

    return left;
}

struct Solution
{
    string s;

    mutable vector<vector<UInt> > mem;
    mutable vector<vector<char> > used;

    Solution(istream & in)
    {
        in >> s;
        mem.assign(s.size() + 1, vector<UInt>(s.size()+ 1));
        used.assign(s.size() + 1, vector<char>(s.size()+ 1, 0));
    }

    UInt smallSolve(int pos, int balance) const
    {
        if(pos>=0)
        {
            if(used[pos][balance])
                return mem[pos][balance];
        }
        UInt ans;
        if(balance == 0)
            ans+=1;

        if(balance)
        {
            int posClose = s.find(')', pos+1);
            if(posClose!=string::npos)
                ans+=smallSolve(posClose, balance - 1);
        }
        int posOpen = s.find('(', pos+1);
        if(posOpen!=string::npos)
            ans+=smallSolve(posOpen, balance + 1);

        if(pos>=0)
        {
            used[pos][balance] = 1;
            mem[pos][balance] = ans;
        }
        return ans;
    }

    UInt fullSolve() const
    {
        return smallSolve(-1, 0);
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //ifstream in("brackets.in");
    //ofstream out("brackets.out");

    Solution solution(cin);

    cout << solution.fullSolve();


    return 0;
}
