#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin >> n >> m;
    
    vector<int> a(100 + 1, 0);
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        a[x]++;
    }

    int l = 0, r = 100 + 1;
    while(l + 1 < r){
        int mid = (l + r)/2;
        int sum = 0;
        for(auto & i : a)
            sum += i / mid;
        if(sum < n)
            r = mid;
        else
            l = mid;
    }
    cout << l;

    return 0;
}