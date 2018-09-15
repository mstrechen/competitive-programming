#include<iostream>
#include<vector>
using namespace std;

const long long MOD = 1000*1000*1000 + 7;

long long sqr(long long x){
    return (x*x) % MOD;
}

long long binpow(int x, long long a){
    if(a == 0)
        return 1;

    if(a & 1)
        return (sqr(binpow(x, a/ 2)) * x) % MOD;
    else
        return sqr(binpow(x, a/ 2));
}
const  long long DIV6 = binpow(6, MOD - 2);

inline long long get_short_ans(long long n, long long m){
    n -= m;
    return  (((((n - 1) * (n - 2) + (m - 1) * (m - 2)) * n ) % MOD) * ((m * DIV6) % MOD))%MOD;
}

struct SegmentTree{
    int size;
    vector<int> s;
    vector<char> promise;
    SegmentTree(int n) : size(n){
        while(size & (size - 1))
            size &= size - 1;
        if(size != n)
            size *= 2;
        s.assign(size * 2, 0);
        promise.assign(size * 4, 0);
    }

    inline void push(int _i, int L, int R){
        s[_i] = promise[_i] * (R - L + 1);
        promise[_i * 2] = promise[_i * 2 + 1] = promise[_i];
        promise[_i] = -1;
    }

    inline void set(int val, int l, int r, int L, int R, int _i){
        if(promise[_i] != -1)
            push(_i, L, R);
        if(l > r)
            return;

        if(L == l && R == r){
            promise[_i] = val;
            s[_i] = (R - L + 1) * val;
            return;
        }
        int MID = (L + R) >> 1;
        set(val, l, min(r, MID), L, MID, _i * 2);
        set(val, max(l, MID + 1), r, MID + 1, R, _i * 2 + 1);
        s[_i] = s[_i * 2] + s[_i * 2 + 1];
    }

    inline void set(int l, int r, int val){
        set(val, l, r, 1, size, 1);
    }

    inline int get(int l, int r, int L, int R, int _i){
        if(l > r)
            return 0;
        if(promise[_i] != -1)
            push(_i, L, R);
        if(l == L && r == R)
            return s[_i];
        int MID = (L + R) >> 1;

        return get(l, min(r, MID), L, MID, _i * 2)
              + get(max(l, MID + 1), r, MID + 1, R, _i * 2 + 1);
    }

    inline int get(int l, int r){
        return get(l, r, 1, size, 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    //cin >> n;
    n = 100000;
    vector<SegmentTree> ST(31, n);
    for(int i = 0; i < n; i++){
        int x;
        //cin >> x;
        x = rand();
        for(int bit = 30; bit >= 0; bit--)
            ST[bit].set(i + 1, i + 1, (x >> bit) & 1);
    }
    int q;
    //cin >> q;
    q = 100000;
    for(int i = 0; i < q; i++){
        char c; int l, r;
        //cin >> c >> l >> r;
        c = '?';
        l = rand() + 1, r = rand() + 1;
        if(l > r) swap(r, l);

        if(c == '?'){
            long long ans = 0;
            for(long long bit = 30; bit >= 0; bit--)
                ans += (get_short_ans(r - l + 1, ST[bit].get(l, r)) << bit) % MOD;
            //cout << ans % MOD << '\n';
        }
        else{
            int x;
            cin >> x;
            for(int bit = 30; bit >= 0; bit--)
                ST[bit].set(l, r, (x >> bit) & 1);
        }
    }


    return 0;
}


