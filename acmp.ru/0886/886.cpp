#include<iostream>
#include<vector>

using namespace std;

using Ull = unsigned long long;
using HashPair = pair<Ull, long long>;

const long long MOD = 1000*1000*1000+7;
const Ull MUL = 31;

struct Hash
{
    vector<Ull> pow64, hash64;
    vector<long long> powP, hashP;
    Hash(const string & s = "") :  pow64(s.size()+1), hash64(s.size()+1),
                                       powP(s.size()+1), hashP(s.size()+1)
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

    HashPair getHash(int l, int r)
    {
        if(l>r)
            return {0,0};
        return {getHash64(l,r), getHashP(l,r)};
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> s;

    n = s.size();
    s += s;

    Hash H(s);

    int ans = 1;

    for(int i = 1; i < n; i++){
        bool ok = true;
        auto firstHash = H.getHash(n - i + 1, n);
        for(int k = 1; ok && k*i <= (int)s.size(); k++){
            ok &= firstHash == H.getHash((k - 1) * i + 1, k*i);
        }
        ans += ok;
    }
    cout << ans;

    return 0;
}
