#include<iostream>
#include<vector>
#include<cassert>
 
using namespace std;
 
 
using Ull = unsigned long long;
 
const long long MOD = 1000*1000*1000+7;
const Ull MUL = 97;
 
struct Hash
{
    vector<Ull> pow64, hash64;
    vector<long long> powP, hashP;
    string s;
    Hash(const string & source = "") : hashP(source.size()+1), hash64(source.size()+1),
                                   powP(source.size()+1),  pow64(source.size()+1),
                                   s(source)
    {
        hashP[0] = 0;
        hash64[0] = 0;
        powP[0] = 1;
        pow64[0] = 1;
        for(int i = 0; i<(int)s.size(); i++)
        {
            hash64[i+1] = hash64[i]*MUL + (s[i] - 32);
            hashP[i+1] = (hashP[i]*MUL + (s[i] - 32))%MOD;
            pow64[i+1] = pow64[i]*MUL;
            powP[i+1] = (powP[i]*MUL)%MOD;
        }
    }
 
    long long getHashP(int l, int r)
    {
        assert(l<=r);
 
        long long tmp = (hashP[r] - hashP[l-1]*powP[r-l+1])%MOD;
        return tmp + (tmp<0?MOD:0);
    }
 
    Ull getHash64(int l, int r)
    {
        assert(l<=r);
        return hash64[r] - hash64[l-1]*pow64[r-l+1];
    }
 
    bool isEqual(int l1, int l2, int len)
    {
        if(len == 0)
            return 1;
        assert(l1 + len - 1 < (int)hash64.size());
        assert(l2 + len - 1 < (int)hash64.size());
 
        return (getHash64(l1, l1+len-1) == getHash64(l2, l2+len-1) &&
                getHashP(l1, l1+len-1) == getHashP(l2, l2+len-1));
    }
 
    bool isLess(int l1, int l2, int len)
    {
        if(len == 0)
            return 0;
        assert(l1 + len - 1 < (int)hash64.size());
        assert(l2 + len - 1 < (int)hash64.size());
 
        if(isEqual(l1,l2,len))
            return false;
 
        int l = 0, r = len;
        while(l+1<r)
        {
            int mid = (l+r)/2;
            if(isEqual(l1,l2,mid))
                l = mid;
            else
                r = mid;
        }
        return s[l1 + l - 1] < s[l2 + l - 1];
    }
};
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
 
    cin >> s;
 
    Hash myHash(s+s);
 
 
 
    int minShift = 1;
    for(int i = 2; i<=(int)s.size(); i++)
    {
        if(myHash.isLess(i+1, minShift, s.size() ) )
            minShift = i;
    }
 
    for(int i = 0; i<(int)s.size(); i++)
        cout << myHash.s[minShift+i-1];
 
    return 0;
}