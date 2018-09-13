#include<iostream>
#include<string>


using namespace std;

int b[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 365;

    int a[365];
    a[0] = 0;

    for(int i = 1; i<n; i++)
        a[i] = (a[i-1]+1)%7;

    string s1, s2;
    int d1, d2;
    cin >> s1 >> s2;

    if(s1=="monday")
        d1 = 0;
    if(s1=="tuesday")
        d1 = 1;
    if(s1=="wednesday")
        d1 = 2;
    if(s1=="thursday")
        d1 = 3;
    if(s1=="friday")
        d1 = 4;
    if(s1=="saturday")
        d1 = 5;
    if(s1=="sunday")
        d1 = 6;

    if(s2=="monday")
        d2 = 0;
    if(s2=="tuesday")
        d2 = 1;
    if(s2=="wednesday")
        d2 = 2;
    if(s2=="thursday")
        d2 = 3;
    if(s2=="friday")
        d2 = 4;
    if(s2=="saturday")
        d2 = 5;
    if(s2=="sunday")
        d2 = 6;

    d1 = d1-d2;

    int current = 0;
    for(int i = 0; i<11; i++)
    {
        if(a[current]-a[current+b[i]] == d1)
        {
            cout << "YES";
            return 0;
        }
        current+=b[i];
    }
    cout << "NO";



    return 0;
}
