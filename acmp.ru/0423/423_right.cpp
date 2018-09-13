#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct longInteger
{
    vector<int> _digits;

    longInteger(int a = 0)
    {
        _digits.clear();
        while(a)
        {
            _digits.push_back(a%10);
            a/=10;
        }
    }

    void print()
    {
        if(_digits.size()==0)
            cout << 0;
        else
        {
            for(int i = _digits.size()-1; i>=0; i--)
                cout << _digits[i];
        }
    }
};

longInteger operator + (longInteger a,longInteger b)
{
    if(a._digits.size()<b._digits.size())
        swap(a,b);

    a._digits.push_back(0);

    for(int i = 0; i<a._digits.size()-1; i++)
    {
        if(i<b._digits.size())
            a._digits[i]+=b._digits[i];
        a._digits[i+1]+=a._digits[i]/10;
        a._digits[i]%=10;
    }
    if(*a._digits.rbegin()==0)
        a._digits.pop_back();
    return a;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    string s;

    (longInteger(23)+longInteger(39)).print();
    cout << endl;

    cin >> s;

    vector<longInteger> dyn(s.size()+1, longInteger(0));
    dyn[s.size()] = longInteger(1);
    s+='!';

    for(int i = s.size()-2; i>=0; i--)
    if(s[i]!='0')
    {
        if((s[i]>'3'||(s[i]=='3'&& s[i+1]>'3') )||s[i+1]!='!')
            dyn[i] = dyn[i+1];
        else
            dyn[i] = dyn[i+1]+dyn[i+2];
    }
    for(int i = s.size()-1; i>=0; i--)
    {
        dyn[i].print();
        cout << endl;
    }

    dyn[0].print();
	return 0;
}
