#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;

int len(int x){
    if(x >= 1000*1000)
        return 1000*10000;
    if(x >= 1000*100)
        return 1000*1000;
    if(x >= 1000*10)
        return 1000*100;
    if(x >= 1000)
        return 10000;
    if(x >= 100)
        return 1000;
    if(x >= 10)
        return 100;
    if(x >= 1)
        return 10;
}

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

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i] * 1LL * len(b[i]) + b[i];
    cout << sum;


    return 0;
}

