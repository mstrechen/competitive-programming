#include<iostream>
#include<vector>



using namespace std;

struct Fenwick{
    int size, delta;
    vector<int> a;
    Fenwick(int n, int delta) : size(n + delta), delta(delta), a(size, 0){
    }

    void clear(){
        a.assign(size, 0);
    }
    int getP(int x){
        int s = 0;
        //cout << endl;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1 )
           // cout << i <<'!',
            s += a[i];
            //cout << endl;
        return s;
    }
    void setP(int x){
        x += delta;
        for(int i = x; i < size; i = ((i + 1) | i) )
            a[i]++;
    }
    int get(int i){
        return getP(i - 1 + delta);
    }
};

struct SegmentTree{
    int size;
    int DELTA;
    vector<int> s;
    SegmentTree(int n, int delta) : size(n + delta), DELTA(delta){
        while(size & (size - 1))
            size &= size - 1;
        if(size != n + delta)
            size *= 2;
        s.assign(size * 2, 0);
    }
    void clear(){s.assign(size * 2, 0);}

    int get(int l, int r, int L, int R, int _i){
        if(l > r)
            return 0;
        if(L == l && R == r)
            return s[_i];

        int mid = (L + R) / 2;
        return get(l,    min(r, mid), L,     mid, _i * 2)
            + get(max(l, mid + 1), r, mid + 1, R, _i * 2 + 1);
    }

    int get(int i){
        return get(1, i + DELTA - 1, 1, size, 1);
    }
    void set(int i, int L, int R, int _i){
        if(i < L || i > R)
            return;
        s[_i]++;

        if(L == R)
            return;
        int mid = (L + R) / 2;
        if(i <= mid)
            set(i, L, mid, _i * 2);
        else
            set(i, mid + 1, R, _i * 2 + 1);
    }
    void set(int i){
        set(i + DELTA, 1, size, 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n;
    cin >> s;

    Fenwick ST(n, 2*n + 20);
    long long ans = 0;
    for(char LET = 'a'; LET <= 'z'; LET++){
        vector<int> p(s.size() + 1, 0);
        ST.clear();
        for(int i = 1; i <= n; i++)
            p[i] = p[i - 1] + (s[i - 1] == LET);
        for(int i = 0; i <= n; i++){
            p[i] *= 2;
            p[i] -= i;
        }
        ST.setP(p[0]);
        for(int i = 1; i <= n; i++){
            ans += ST.get(p[i]);
            ST.setP(p[i]);
        }
    }
    cout << n * 1LL * (n + 1) / 2 - ans;

    return 0;
}

