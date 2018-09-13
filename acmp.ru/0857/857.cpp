#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

using namespace std;

namespace str_work{

    struct double_hash{
        unsigned long hMod, h64;
        const unsigned int DELTA = 97;
        const long MOD = 30*1000 + 7;
        double_hash() : hMod(0), h64(0){}
        double_hash(const double_hash & src) : hMod(src.hMod), h64(src.h64){}
        double_hash(unsigned long hMod,
                    unsigned long h64) : hMod(hMod), h64(h64){}


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
        double_hash operator + ( const double_hash & a) const{
            return double_hash((this->hMod + a.hMod + MOD)%MOD,
                                this->h64 + a.h64);
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
        bool operator < (const double_hash & a) const{
            return (this->hMod < a.hMod) || (this->hMod == a.hMod && this->h64 < a.h64);
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
        double_hash operator [](int i) const{
            return pw[i];
        }
        double_hash get(int l, int r) const{
            return  hs[r] - hs[l] * pw[r - l];
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
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<str_work::double_hash, int> used;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        str_work::hashed_string H(s);

        for(int len = 1; len <= s.size(); len++){
            auto tmpL = H.get(0, len),
                 tmpR = H.get(s.size() - len, s.size());
            if(tmpL == tmpR)
                used[tmpL]++;

        }

    }
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        str_work::hashed_string H(s);
        cout << used[H.get(0, s.size())] << '\n';
    }

    return 0;
}
