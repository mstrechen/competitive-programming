#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int> > h(n);
    for(auto & i : h)
        cin >> i.first >> i.second;
        
    reverse(h.begin(), h.end());
    int minH = 0;
    for(auto & i : h){
        if(min(i.first, i.second) >= minH)
            minH = min(i.first, i.second);
        else if(max(i.first, i.second) >= minH)
            minH = max(i.first, i.second);
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}