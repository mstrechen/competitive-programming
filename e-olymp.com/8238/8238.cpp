#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(2*n);
    for(auto & i : a)
        cin >> i;
    for(auto & i : b)
        cin >> i;
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    for(auto & i : c)
        cout << i << ' ';

    return 0;
}
