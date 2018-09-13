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
    Hash(const string & s = "") : pow64(s.size()+1), hash64(s.size()+1),
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

    hashPair getHash(int l, int r)
    {
        if(l>r)
            return {0,0};
        return {getHash64(l,r), getHashP(l,r)};
    }
};

tuple<int, int, int> getLCS(const string & A, const string & B)
{
    int lLen = 0, rLen = min((int)A.size(), (int)B.size()) + 1;

    Hash hashA(A), hashB(B);
    set<hashPair> hashes;

    while(lLen+1<rLen)
    {
        int mid = (lLen+rLen)/2;

        hashes.clear();
        for(int i = 0; i+mid<=(int)A.size(); i++)
            hashes.insert(hashA.getHash(i+1, i+mid));

        bool noThatHash = 1;
        for(int i = 0; i+mid <= (int)B.size() && noThatHash; i++)
        {
            noThatHash = !hashes.count(hashB.getHash(i+1,i+mid));
        }

        if(noThatHash)
            rLen = mid;
        else
            lLen = mid;
    }

    int posA, posB;
    hashPair found;

    hashes.clear();
    for(int i = 0; i+lLen<=(int)A.size(); i++)
        hashes.insert(hashA.getHash(i+1, i+lLen));


    bool noThatHash = 1;
    for(int i = 0; i+lLen<=(int)B.size() && noThatHash; i++)
    {
        noThatHash = !hashes.count(hashB.getHash(i+1,i+lLen));
        if(!noThatHash)
        {
            posB = i;
            found = hashB.getHash(i+1,i+lLen);
        }
    }

    noThatHash = 1;
    for(int i = 0;  i+lLen<=(int)A.size() && noThatHash; i++)
    {
        noThatHash = !(hashA.getHash(i+1,i+lLen) == found);
        if(!noThatHash)
        {
            posA = i;
        }
    }

    return make_tuple(posA, posB, lLen);
}

char getOpposite(char c)
{
    if(c <= 'B')
        return 'a' + c - 'A';
    return 'A' + c - 'a';
}

string minimize(const string & s)
{
    string st;

    for(int i = 0; i < (int)s.size(); i++)
    {
         if(st.size() &&
            s[i] == getOpposite(st.back()))
            {
                st.pop_back();
            }
         else
            st.push_back(s[i]);
    }

    return st;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string X, Y, Ycopy;

    cin >> X >> Ycopy;

    X = minimize(X);
    Y = minimize(Ycopy);

    int posX, posY, len;
    tie(posX, posY, len) = getLCS(X,Y);

    string res(X.begin(), X.begin()+posX);

    for(int i = posY - 1; i>=0; i--)
        res.push_back(getOpposite(Y[i]));

    res.append(X.begin()+posX, X.begin()+posX+len);

    for(int i = (int) Y.size() - 1; i >= posY+len; i--)
        res.push_back(getOpposite(Y[i]));

    res.append(X.begin()+posX+len, X.end());


    res.erase(posX + posY, len);
    res.insert(posX + posY, Ycopy);

    cout << res;



    return 0;
}
