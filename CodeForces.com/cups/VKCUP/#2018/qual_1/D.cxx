#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

set<string> used;

bool is_pref(const string & a, const string & b){
    if(a.size() > b.size())
        return false;
    for(int i = 0; i < a.size(); i++)
        if(a[i] != b[i])
            return 0;
    return 1;
}

bool check_unique(const string & a){
    auto it = used.lower_bound(a);
    it++;
    if(it == used.end())
        return false;
    return !is_pref(a, *it);
}

int find_minimal_cnt(string & a){
    if(a.size() == 0)
        return 0;
    if(!used.count(a)){
        used.insert(a);
        return a.size();
    }
    int min_ans = a.size();
    
    int l = 1, r = a.size();
    while(l < r){
        int mid = (l + r)/2;
        if(check_unique(string(a.begin(), a.begin() + mid) ) ){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return min(l + 1, min_ans);
}

bool is_letter(char c){
    return c >= 'a' && c <= 'z';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string tmp;
    int ans = 0;
    while(cin.good()){
        getline(cin, tmp);
        string current;
        for(char i : tmp){
            if(is_letter(i)){
                current += i;
            } else {
                ans++;
                ans += find_minimal_cnt(current);
                current.clear();
            }
        }
        ans += find_minimal_cnt(current);
        ans++;
    }
    cout << ans; 
    return 0;
}