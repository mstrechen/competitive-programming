#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>

using namespace std;

using Ull = unsigned long long;
using hashPair = pair<Ull, long long>;

const long long MOD = 1000*1000*1000+7;
const Ull MUL = 31;

struct Hash
{
    vector<Ull> pow64, hash64;
    vector<long long> powP, hashP;
    Hash(const string & s = "") : hashP(s.size()+1), hash64(s.size()+1),
                                       powP(s.size()+1),  pow64(s.size()+1)
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
        long long tmp = (hashP[r] - hashP[l-1]*powP[r-l+1])%MOD;
        return tmp + (tmp<0?MOD:0);
    }

    Ull getHash64(int l, int r)
    {
        return hash64[r] - hash64[l-1]*pow64[r-l+1];
    }

    hashPair getHash(int l, int r)
    {
        if(l>r)
            return {0,0};
        return {getHash64(l,r), getHashP(l,r)};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string A, B;

    cin >> n;
    cin >> A;
    cin >> B;

    int lLen = 0, rLen = n+1;


    Hash hashA(A), hashB(B);
    set<hashPair> hashes;

    while(lLen+1<rLen)
    {
        int mid = (lLen+rLen)/2;

        hashes.clear();
        for(int i = 0; i+mid<=n; i++)
            hashes.insert(hashA.getHash(i+1, i+mid));

        bool noThatHash = 1;
        for(int i = 0; i+mid<=n && noThatHash; i++)
        {
            noThatHash = !hashes.count(hashB.getHash(i+1,i+mid));
        }

        if(noThatHash)
            rLen = mid;
        else
            lLen = mid;
    }

    hashes.clear();
    for(int i = 0; i+lLen<=n; i++)
        hashes.insert(hashA.getHash(i+1, i+lLen));


    bool noThatHash = 1;
    for(int i = 0; i+lLen<=n && noThatHash; i++)
    {
        noThatHash = !hashes.count(hashB.getHash(i+1,i+lLen));
        if(!noThatHash)
            cout << string(B.begin()+i, B.begin()+lLen+i);
    }





    return 0;
}
