#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<unordered_set>
#include<functional>
#include<algorithm>
#include<cassert>
#include<iterator>

using namespace std;

using Ull = unsigned long long;
using HashPair = pair<Ull, long long>;

const long long MOD = 1000*1000*1000 + 7;
const Ull MUL = 5;

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
            int c;
            switch(s[i]){
                case '-' : c = 1; break;
                case '~' : c = 2; break;
                case 'v' : c = 3; break;
                default : c  = 4;
            }
            hash64[i+1] = hash64[i]*MUL + c;
            hashP[i+1] = (hashP[i]*MUL + c)%MOD;
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


struct OpenAddressHashTable
{
    static const int size{6*1000*1000 + 11}; //prime number greater than 4'000'000
    static const int step{50000};
    HashPair cleared{make_pair(0ULL, -1LL)};

    vector<HashPair> a{size, cleared};

    int hash(const HashPair &toHash) const {
    	return int((toHash.first + (Ull)toHash.second)%size);
    }

    int hash2(const HashPair &toHash) const {
    	return int((toHash.first + (Ull)toHash.second)%step) + 1;
    }

    void clear()
    {
        a.assign(size, cleared);
    }

    void insert(const HashPair & toInsert)
    {
    	int first = hash(toInsert);
        int i = first;
        int realStep = -1;
        while (true)
        {
            if(a[i] == cleared)
            {
                a[i] = toInsert;
                return;
            }
            if(a[i] == toInsert)
                return;

            if (realStep == -1) {
            	realStep = hash2(toInsert);
            }
            i+=realStep;
            if (i >= size) {
            	i -= size;
            }
            assert(i!=first && "NO PLACE");
        }
    }

    int count(const HashPair & toFind)
    {
    	int first = hash(toFind);
        int i = first;
        int realStep = -1;
        while (true)
        {
            if(a[i] == cleared)
            {
                return 0;
            }
            if(a[i] == toFind)
                return 1;
            if (realStep == -1) {
            	realStep = hash2(toFind);
            }
            i+=realStep;
            if (i >= size) {
            	i -= size;
            }
            assert(i!=first && "NO PLACE");
        }
    }

};

struct Buckets
{
    vector<int> beginnings;
    vector<int> next;
    vector<HashPair> mem;
    int firstUnused{0};

    Buckets(int cnt, int capacity) : beginnings(cnt, -1), next(capacity, -1), mem(capacity){}

    void clear()
    {
        beginnings.assign(beginnings.size(), -1);
        firstUnused = 0;
    }

    void push_back(int bucket, const HashPair & toPush)
    {
        mem[firstUnused] = toPush;
        next[firstUnused] = beginnings[bucket];
        beginnings[bucket] = firstUnused++;
    }

    struct Iterator : iterator<std::forward_iterator_tag, HashPair>
    {
        Buckets & src;
        int pos;
        Iterator(Buckets & src, int pos = -1) : src(src), pos(pos){};

        Iterator & operator ++ ()
        {
            pos = src.next[pos];
            return *this;
        }
        HashPair & operator *()
        {
            return src.mem[pos];
        }
        bool operator == (const Iterator & a)
        {
            return (&src == &a.src) && (pos == a.pos);
        }
        bool operator != (const Iterator & a)
        {
            return (&src != &a.src) || (pos != a.pos);
        }
    };

    Iterator getBegin(int bucket)
    {
        return Iterator(*this, beginnings[bucket]);
    }
    Iterator getEnd()
    {
        return Iterator(*this);
    }
};

struct SeparateChainingHashTable
{
    static const int bucketsCnt{6*1000*1000};
    static const int size{1000*1000 + 5};

    Buckets a{bucketsCnt, size};
    int hash(const HashPair &toHash) const
    {
    	return int((toHash.first + (Ull)toHash.second)%bucketsCnt);
    }

    void clear()
    {
        a.clear();
    }

    void insert(const HashPair & toInsert)
    {
        int hashed = hash(toInsert);
        if(!any_of(a.getBegin(hashed), a.getEnd(),
                   [toInsert](const HashPair & toCheck){return toInsert == toCheck;} ))
        {
            a.push_back(hashed, toInsert);
        }
    }

    int count(const HashPair & toFind)
    {
        int hashed = hash(toFind);
        return any_of(a.getBegin(hashed), a.getEnd(),
                   [toFind](const HashPair & toCheck){return toFind == toCheck;} );
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;

    cin >> A;
    cin >> B;
    int lLen = 0, rLen = min(A.size(), B.size()) + 1;


    Hash hashA(A), hashB(B);
    vector<HashPair> hashes;

    while(lLen+1<rLen)
    {
        int mid = (lLen+rLen)/2;

        hashes.clear();
        for(int i = 0; i+mid <= (int)A.size(); i++)
            hashes.push_back(hashA.getHash(i+1, i+mid));

        sort(hashes.begin(), hashes.end());

        bool noThatHash = 1;
        for(int i = 0; i + mid <= (int)B.size() && noThatHash; i++)
        {
            noThatHash = !binary_search(hashes.begin(), hashes.end(), hashB.getHash(i+1,i+mid));
        }

        if(noThatHash)
            rLen = mid;
        else
            lLen = mid;
    }
    cout << lLen << endl;


    return 0;
}
