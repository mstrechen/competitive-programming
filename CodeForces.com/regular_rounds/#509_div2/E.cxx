#include<iostream>
#include<set>
#include<vector>
#include<numeric>
#include<vector>

const int INF = 2e9;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> cnt(n);
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        cnt[x]++, cnt[y]++;
    }
    if(cnt.back() != n - 1 || cnt[n - 2] == 0){
        cout << "NO";
        return 0;
    }
    for(auto it = cnt.begin(); it != cnt.end() - 1; it++){
        if(accumulate(cnt.begin(), it + 1, 0) > it - cnt.begin() + 1){
            cout << "NO";
            return 0;
        }
    }

    vector<pair<int, int> > ans;
    set<int> emp;
    for(int i = 0; i < n; i++)
        if(cnt[i] == 0)
            emp.insert(i);
    
    cout << "YES\n";
    int prev = n - 1;
    for(int cur = n - 2; cur >= 0; cur--){
        if(cnt[cur] <= 0)
            continue;
        for(int i = 1; i < cnt[cur]; i++){
            cout << *emp.rbegin() + 1 << ' ' << prev + 1 << '\n';
            prev = *emp.rbegin();
            emp.erase(*emp.rbegin()); 
        }
        cout << prev + 1 << ' ' << cur + 1 << '\n';
        prev = cur;
    }
    
    return 0;  
}