#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> ends(k);
    for(int i = 0; i < k; i++)
            ends[i] = i+1;

    int DIV = (n - k)/k;
    int MOD = (n - k)%k;

    if(MOD != 1){

        if(MOD == 0)
            cout << DIV*2 + 1 << '\n';
        else
            cout << DIV*2 + 3 << '\n';
    }
    else{
            cout << DIV*2 + 2<< '\n';
    }

    for(int i = k; i < n; i++){
        cout << ends[i%k] << ' ' << i+1 << '\n';
        ends[i%k] = i+1;
    }

    for(int i = 1; i < k; i++){
        cout << ends[i] << ' ' << ends[0] << '\n';
    }

    return 0;
}
