#include<iostream>

using namespace std;

const long long NEO = 1;
long long getId(char c)
{
    if(c>='a')
    {
        return c-'a'+32;
    }
    else
    {
        return c-'A';
    }
}
int a[100];
int main()
{
    ios::sync_with_stdio(false);
    string s;
    int tmp;
    long long mask = 0, currMask = 0;

    cin >> tmp;
    cin >> s;
    for(int i = 0; i<s.size(); i++)
    {
        mask|=(NEO<<getId(s[i]));
    }
    int minCost = 100500;

    int l = 0;
    for(int r = 0; r<s.size(); r++)
    {
        currMask|=(NEO<<getId(s[r]));
        a[getId(s[r])]++;

        while(a[getId(s[l])]>1)
        {
            a[getId(s[l])]--;
            l++;
        }

        if(currMask == mask)
        {
            minCost = min(minCost, r-l+1);
        }
    }
    cout << minCost;
    return 0;
}
