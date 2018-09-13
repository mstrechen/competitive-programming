#include<iostream>
#include<vector>
#include<functional>
using namespace std;

const int OO = 2*1000*1000*1000;

struct get_max{
     int operator ()(int a, int b){
         return max(a, b);
     } 
};

template<typename OP, int NEUTRAL>
struct segment_tree{
    int size;
    vector<int> a;
    OP operation;
    segment_tree(const vector<int> & src) : size(src.size()){
        while(size & (size - 1))
            size &= size - 1;
        if(size != (int)src.size())
            size *= 2;
        a.assign(size * 2, NEUTRAL);
        for(int i = 0; i < (int)src.size(); i++)
            a[i + size] = src[i];

        for(int i = size - 1; i > 0; i--)
            a[i] = operation(a[i*2], a[i*2 + 1]);
    } 
    int get(int l, int r, int L, int R, int _i){
        if(l > r)
            return NEUTRAL;
        if(L == l && R == r)
            return a[_i];
        int mid = (L + R)/2;
        return operation(get(l, min(r, mid), L, mid, _i*2),
                  get(max(mid + 1, l), r, mid + 1, R, _i*2 + 1));
    }
    int get(int l, int r){
        return get(l + 1, r + 1, 1, size, 1); 
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a)
        cin >> i;
    segment_tree<get_max, -OO> st(a);
    
    
    long long ans = 0;
    long long prev_hg = 0;
    for(int i = n - 1; i >= 0; i--){
        long long h = max(st.get(0, i) + 1LL, prev_hg);
        ans += h - 1 - a[i];
        prev_hg = h;
        prev_hg--;
    }
    cout << ans;

    return 0;
}