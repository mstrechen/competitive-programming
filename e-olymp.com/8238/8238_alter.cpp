#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>


using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto & i : a)
        cin >> i;
    for(auto & i : b)
        cin >> i;

    ostream_iterator<int> out_it(cout, " ");

    merge(a.begin(), a.end(), b.begin(), b.end(), out_it);

    return 0;
}
