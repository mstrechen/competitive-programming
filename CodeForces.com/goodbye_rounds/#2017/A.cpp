#include<iostream>
#include<set>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> a = {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};
    string s;
    cin >> s;
    int ans = 0;
    for(auto i : s)
        ans += a.count(i);

    cout << ans;


    return 0;
}
