#include<iostream>
#include<vector>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long L;
    cin >> n >> L;
    vector<unsigned long long> a(n);
    for(auto & i : a)
        cin >> i;

    a.resize(32, (unsigned long long)9e18);

    for(int i = 1; i < a.size(); i++)
        a[i] = min(a[i], 2*a[i - 1]);

    unsigned long long cost = 0;
    for(int i = 0; i <= 30; i++)
        if((L >> i) & 1){
            cost = min(a[i], cost);
            cost += a[i];
        }
        else{
            cost = min(a[i], cost);
        }

    cout << cost;



    return 0;
}
