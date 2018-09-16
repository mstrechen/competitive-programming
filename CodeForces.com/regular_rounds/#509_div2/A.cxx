#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a)
        cin >> i;

    cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) + 1 - n;

    return 0;
}