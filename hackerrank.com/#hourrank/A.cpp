#include<iostream>
#include<string>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long count = 0;
    long long n = 0;
    string s;

    cin >> s;
    cin >> n;

    long long n1 = n/s.size();
    n%=s.size();
    long long summ = 0;

    for(int i = 0; i<s.size(); i++)
        summ+=s[i]=='a';

    summ*=n1;

    for(int i = 0; i<n; i++)
        summ+=s[i]=='a';

    cout << summ;

    return 0;
}
