#include<iostream>
#include<vector>

using namespace std;

namespace str_work{

    struct double_hash{
        unsigned long long hMod, h64;
        const unsigned int DELTA = 97;
        const long long MOD = 1000*1000*1000 + 7;
        double_hash() : hMod(0), h64(0){}
        double_hash(const double_hash & src) : hMod(src.hMod), h64(src.h64){}
        double_hash(unsigned long long hMod,
                    unsigned long long h64) : hMod(hMod), h64(h64){}


        double_hash operator + ( char b) const{
            return double_hash((this->hMod * DELTA + (b - 32))%MOD,
                                this->h64 * DELTA + (b - 32));
        }
        double_hash operator * ( const double_hash & a) const{
            return double_hash((this->hMod * a.hMod)%MOD,
                                this->h64 * a.h64);
        }
        double_hash operator - ( const double_hash & a) const{
            return double_hash((this->hMod - a.hMod + MOD)%MOD,
                                this->h64 - a.h64);
        }


        double_hash & operator = (const double_hash & src){
            this->hMod = src.hMod;
            this->h64 = src.h64;
            return *this;
        }

        double_hash operator ++ () const{
            return double_hash((this->hMod * DELTA)%MOD,
                                this->h64 * DELTA);
        }

        bool operator == (const double_hash & a){
            return this->hMod == a.hMod && this->h64 == a.h64;
        }



    };


    struct hashed_string{
        string s;
        vector<double_hash> hs, pw;

        hashed_string() : s(""), hs(0), pw(0) {}
        hashed_string(string s) : s(s){
            build();
        }

        void build(){
            hs.assign(1, double_hash(0, 0));
            pw.assign(1, double_hash(1, 1));
            int n = (int)s.size();
            hs.reserve(n + 1);
            pw.reserve(n + 1);

            for(int i = 0; i < n; i++){
                hs.push_back(hs[i] + s[i]);
                pw.push_back(++pw[i]);
            }
        }

        double_hash operator ()(int l, int r) const{
            return  hs[r] - hs[l] * pw[r - l];
        }
        double_hash get(int l, int r) const{
            return  hs[r] - hs[l] * pw[r - l];
        }

        bool compare_subs(int l1, int r1, int len) const{
            int L = 0, R = len + 1;
            while(L + 1 < R){
                int mid = (L + R)/2;
                if(this->get(l1, l1 + mid) == this->get(r1, r1 + mid))
                    L = mid;
                else
                    R = mid;
            }
            if(L == len)
                return 0;
            return s[l1 + L] < s[r1 + L];
        }
    };

    istream & operator >> (istream & in, hashed_string & toRead){
        in >> toRead.s;
        toRead.build();
        return in;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, double_s;
    cin >> s;
    double_s = s + s;

    str_work::hashed_string S(double_s);

    int minStr = 0;

    for(int i = 1; i < (int)s.size(); i++){
        if(S.compare_subs(i, minStr, (int)s.size())){
            minStr = i;
        }
    }

    cout << string(double_s.begin() + minStr, double_s.begin() + minStr +(int)s.size());


    return 0;
}
