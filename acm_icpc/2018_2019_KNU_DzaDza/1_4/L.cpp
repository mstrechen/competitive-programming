#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1000*1000*1000 + 7;

long long get_short_ans(long long n, long long m){
    n -= m;
    long long a1 = n * (n - 1) * (n - 2);
    a1 /= 6;
    long long a2 = m * (m - 1) * (m - 2);
    a2 /= 6;

    a1 %= MOD, a2 %= MOD;
    long long ans = a1 * m + a2 * n;
    ans %= MOD;
    cout << n << ' ' << m << ' ' << ans <<  endl;
    return ans;
}

struct SegmentTree{
    int size;
    vector<int> s, promise;
    SegmentTree(int n) : size(n){
        while(size & (size - 1))
            size &= size - 1;
        if(size != n)
            size *= 2;
        s.assign(size * 2, 0);
        promise.assign(size * 2, 0);
    }

    void push(int _i, int L, int R){
        if(promise[_i] != -1)
            s[_i] = promise[_i] * (R - L);
        if(L != R)
            promise[_i * 2] = promise[_i],
            promise[_i * 2 + 1] = promise[_i];
        promise[_i] = -1;
    }

    void set(int val, int l, int r, int L, int R, int _i){
        push(_i, L, R);
        if(l > r)
            return;
        if(L == l && R == r){
            promise[_i] = val;
            s[_i] = (R - L) * val;
            return;
        }
        int MID = (L + R) / 2;
        set(val, l, min(r, MID), L, MID, _i * 2);
        set(val, max(l, MID + 1), r, MID + 1, R, _i * 2 + 1);
        s[_i] = s[_i * 2] + s[_i * 2 + 1];
    }

    void set(int l, int r, int val){
        set(val, l, r, 1, size, 1);
    }

    int get(int l, int r, int L, int R, int _i){
        if(l > r)
            return 0;
        push(_i, L, R);
        if(l == L && r == R)
            return s[_i];
        int MID = (L + R) / 2;

        return get(l, min(r, MID), L, MID, _i * 2)
            + get(max(l, MID + 1), r, MID + 1, R, _i * 2 + 1);
    }

    int get(int l, int r){
        return get(l, r, 1, size, 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<SegmentTree> ST(31, n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int bit = 30; bit >= 0; bit--)
            ST[bit].set(i + 1, i + 1, (x >> bit) & 1);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        char c; int l, r;
        cin >> c >> l >> r;
        if(c == '?'){
            long long ans = 0;
            for(int bit = 30; bit >= 0; bit--)
                ans += (get_short_ans(r - l + 1, ST[bit].get(l, r) << bit) % MOD);
            cout << ans % MOD << '\n';
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

