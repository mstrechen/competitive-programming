#include<iostream>
#include<fstream>
#include<bitset>
#include<vector>
#include<set>

using namespace std;

int n = 7;
string s = "out8.txt";



ofstream cout_(s);

vector<int> a[3];

vector<int> st;
int maxn = 0;
set<int> b[3];

void rec(int _i, int len)
{
    bool isSmth = 0;
    for(int i = _i+1; i<a[0].size(); i++)
    {
        if(b[0].count(a[0][i])==0&&
           b[1].count(a[1][i])==0&&
           b[2].count(a[2][i])==0)
            {
                isSmth = 1;
                b[0].insert(a[0][i]);
                b[1].insert(a[1][i]);
                b[2].insert(a[2][i]);
                st.push_back(i);
                rec(i, len+1);
                st.pop_back();
                b[0].erase(a[0][i]);
                b[1].erase(a[1][i]);
                b[2].erase(a[2][i]);
            }
    }
    if(isSmth==0&&len>=maxn)
    {
        for(int i = 0; i<len; i++)
            cout_ << a[0][st[i]] << ' '<< a[1][st[i]] << ' '<< a[2][st[i]] << "  " ;

       cout_ << len << endl;
        maxn = len;
    }
}

int main()
{
    ios::sync_with_stdio(false);


    for(int i = 0; i<=5; i++)
    for(int j = 0; j<=5; j++)
    for(int k = 0; k<=5; k++)
        if(i+j+k==n)
        {
            a[0].push_back(i);
            a[1].push_back(j);
            a[2].push_back(k);
        }

    rec(-1,0);



    return 0;
}
