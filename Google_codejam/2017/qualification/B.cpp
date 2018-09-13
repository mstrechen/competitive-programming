#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

struct num
{
    string s;
};

istream & operator >> (istream & in, num & toRead)
{
    in >> toRead.s;
    return in;
}
ostream & operator << (ostream & out, const num & toWrite)
{
    if(toWrite.s.size() == 0)
        out << s;
    else
    {
        if(s[0]>s[1])
        {

        }
        else
        {

        }
    }
    return out;
}


int main()
{
    ifstream cin("B.in");
    ofstream cout("B.out");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int I = 0; I<n; I++)
    {

    }

    return 0;
}
