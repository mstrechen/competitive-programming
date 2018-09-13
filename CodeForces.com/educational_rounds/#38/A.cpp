#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    set<int> lt = {'a', 'e', 'i', 'o', 'u', 'y'};
    string s;
    int n;
    cin >> n;
    cin >> s;
    
    string ans;
    reverse(s.begin(), s.end());

    for(int i = 0; i < n; i++){
        if(i == n-1 || lt.count(s[i]) == 0 || lt.count(s[i + 1]) == 0)
            ans.push_back(s[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    

    return 0;
}