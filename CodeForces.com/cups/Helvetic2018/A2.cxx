#include<iostream>
#include<vector>

using namespace std;


const long long MOD = 1e9 + 7;
const unsigned long long MUL = 31;
struct hash_pair{

    unsigned long long h1;
    long long h2;
    hash_pair() : h1(0), h2(0){}
    hash_pair(const hash_pair & src) : h1(src.h1), h2(src.h2){}
    hash_pair(unsigned long long h1, long long h2) : h1(h1), h2(h2){}

    const hash_pair & operator = (const hash_pair & src){
        h1 = src.h1;
        h2 = src.h2;
        return *this;
    }

    void add(char c){
        h1 *= MUL;
        h2 *= MUL;
        h1 += c - 'a' + 1;
        h2 += c - 'a' + 1;
        h2 %= MOD;
    }
};

hash_pair operator + (const hash_pair & lhs, const hash_pair & rhs){
    return {lhs.h1 + rhs.h1, (lhs.h2 + rhs.h2) % MOD};
}
hash_pair operator * (const hash_pair & lhs, const hash_pair & rhs){
    return {lhs.h1 * rhs.h1, (lhs.h2 * rhs.h2) % MOD};
}

hash_pair operator - (const hash_pair & lhs, const hash_pair & rhs){
    return {lhs.h1 - rhs.h1, ((lhs.h2 - rhs.h2) % MOD + MOD)%MOD };
}

struct hash_s{
    vector<hash_pair> h;
    vector<hash_pair> p;
    hash_s(string s = "") : h(s.size() + 1), p(s.size() + 1){
        p[0].h1 = 1;
        p[0].h2 = 1;
        for(int i = 1; i <= (int)s.size(); i++){
            h[i] = h[i - 1];
            p[i] = p[i - 1];
            h[i].add(s[i - 1]);
            p[i].add('a' - 1);
        }
    }

    hash_pair get(int l, int r){
        return h[r] - h[l] * p[r - l];   
    }
};

bool operator == (const hash_pair & a, const hash_pair & b){
    return a.h1 == b.h1 && a.h2 == b.h2;
}
bool operator != (const hash_pair & a, const hash_pair & b){
    return a.h1 != b.h1 || a.h2 != b.h2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<string> s1(n), s2(m);
    for(auto & i : s1)
        cin >> i;
    for(auto & i : s2)
        cin >> i;
    
    vector<hash_s> h1(n), h2(m);
    for(int i = 0; i < n; i++){
        h1[i] = hash_s(s1[i]);
    }
    for(int i = 0; i < m; i++){
        h2[i] = hash_s(s2[i]);
    }

    vector<hash_pair> p1(n);
    for(int i = 0; i < n; i++)
        p1[i] = h1[i].get(0, m);
    vector<vector<hash_pair> > p2(m, vector<hash_pair>(n - m + 1));
     
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n - m + 1; j++)
            p2[i][j] = h2[i].get(j, j + m);
    
    for(int i = 0; i < n - m + 1; i++)
        for(int j = 0; j < n - m + 1; j++){
            bool flag = 1;
            for(int offset = 0; offset < m && flag; offset++)
                flag &= p1[i + offset] == p2[offset][j];
            if(flag){
                cout << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
            


    return 0;
}