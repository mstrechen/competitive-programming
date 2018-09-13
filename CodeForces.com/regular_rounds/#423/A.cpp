#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

string tt;

struct rec{
    int l, r;
    string & s;
    rec(int l = 0, int r = 0, string & s = tt) : l(l), r(r), s(s){}
};
bool operator < (const rec & a, const rec & b){
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> ss(n);

    set<rec> pos;

    int len = 0;
    for(int i = 0; i < n; i++){
        int k;
        cin >> ss[i];
        cin >> k;

        for(int j = 0; j < k; j++){
            int p;
            cin >> p;
            pos.insert(rec(p - 1, p + ss[i].size() - 1, ss[i]));
            len = max(len, p + (int)ss[i].size() - 1);
        }
    }

    string s(len, 'a');


    for(int i = 0; i < len; i++){
        auto it = pos.lower_bound(rec(i, 0));
        if(it == pos.end() || it->l != i){
            if(it == pos.begin()){
                continue;
            }
            --it;
        }
        if(it->r <= i || it->l > i){
            continue;
        }
        s[i] = it->s[i - it->l];
    }

    cout << s;
    return 0;
}
