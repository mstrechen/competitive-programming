#include<iostream>
#include<vector>

using namespace std;

const long long STEP = 2e9;

int mostleft_bit(int x){
    if(x == 0)
        return -1;
    return 31 - __builtin_clz(x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int x, d;
    cin >> x >> d;

    vector<long long> ans;
    long long cur = 1;

    for(int i = mostleft_bit(x); x > 0; ){
        for(int j = 0; j < i; j++)
            ans.push_back(cur);
        ans.push_back(cur + STEP);
        
        cur += 2*STEP;
        x -= 1 << i;
        i = mostleft_bit(x);
    }
    cout << ans.size() << '\n';
    for(auto & i : ans)
        cout << i << ' ';


    return 0;
}