#include<iostream>
#include<bitset>
#include<vector>
#include<set>

using namespace std;

int dividers[168] = {2,3,5,7,11,13,17,19,23,29,31,37,
41,43,47,53,59,61,67,71,73,79,83,89,
97,101,103,107,109,113,127,131,137,139,149,151,
157,163,167,173,179,181,191,193,197,199,211,223,
227,229,233,239,241,251,257,263,269,271,277,281,
283,293,307,311,313,317,331,337,347,349,353,359,
367,373,379,383,389,397,401,409,419,421,431,433,
439,443,449,457,461,463,467,479,487,491,499,503,
509,521,523,541,547,557,563,569,571,577,587,593,
599,601,607,613,617,619,631,641,643,647,653,659,
661,673,677,683,691,701,709,719,727,733,739,743,
751,757,761,769,773,787,797,809,811,821,823,827,
829,839,853,857,859,863,877,881,883,887,907,911,
919,929,937,941,947,953,967,971,977,983,991,997};


pair<bitset<168>, int> factorize(int n)
{
    pair<bitset<168>, int> res;
    for(int i = 0; i<168&&dividers[i]<=n; i++)
    {
        if(n%dividers[i]==0)
        {
            res.first[i]=1;
            while(n%dividers[i]==0)
                n/=dividers[i];
        }
    }
    res.second = n;
    return res;
}

struct netOfDividers
{
    bitset<168> a;
    set<int> big;

    netOfDividers()
    {
        a.reset();
        big.clear();
    }

    bool isIn(pair<bitset<168>, int> tmp)
    {
        tmp.first&=a;
        if(tmp.first.count()||big.count(tmp.second))
            return 1;
        return 0;
    }
    void eject(pair<bitset<168>, int> tmp)
    {
        a&=~tmp.first;
        big.erase(tmp.second);
    }
    void insert(pair<bitset<168>, int> tmp)
    {

        a|=tmp.first;
        if(tmp.second!=1)
            big.insert(tmp.second);
    }

} aa;

int a[100500];

int main()
{
    ios::sync_with_stdio(false);
    int _n;

    cin >> _n;

    pair<bitset<168>,int> tmp;
    for(int i = 0; i<_n; i++)
    {
        int n;
        cin >> n;
        aa = netOfDividers();
        for(int i = 0; i<n; i++)
            cin >> a[i];

        int l = 0, r = 0;
        int maxRes = 0;
        for(r = 0; r<n; r++)
        {
            tmp = factorize(a[r]);
            while(aa.isIn(tmp))
                aa.eject(factorize(a[l++]));
            aa.insert(tmp);
            maxRes = max(maxRes, r-l);
        }
        if(maxRes==0)
            cout << -1;
        else
            cout << maxRes+1;
        cout << '\n';

    }

    return 0;
}
