#include<iostream>
#include<algorithm>
#include<string>


using namespace std;

int getDigitModule(int num)
{
    if(num<10)
        return num;
    return getDigitModule(num%10 + (num/10)%10 + (num/100)%10);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int allSum = accumulate(s.begin(),s.end(),0,[](int sum, char c){return sum + c - '0';});

    int alterSum = s[0] - '0';

    for(int i = 1; i<s.size(); i++)
    {
        if(getDigitModule(alterSum) == getDigitModule(allSum - alterSum))
        {
            cout << "YES";
            return 0;
        }
        alterSum +=s[i] - '0';
    }
    cout << "NO";

    return 0;
}
