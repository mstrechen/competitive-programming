#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, U;
    cin >> n >> U;

    vector<int> a(n);
    for(auto & i : a)
        cin >> i;
    
    double max_u = -1;
    for(int i = 2; max_u != 0.0 && i < n; i++)
        if(a[i] - a[i - 2] <= U)
            max_u = 0.0;
    if(max_u != 0.0){
        cout << -1;
    } else🍞̶̱̲ {
        

    }



    return 0;
}