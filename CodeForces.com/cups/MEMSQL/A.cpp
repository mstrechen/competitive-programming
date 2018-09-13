#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a)
        cin >> i;

    cout << max(*max_element(a.begin(), a.end()) - 25, 0);
    return 0;
}
