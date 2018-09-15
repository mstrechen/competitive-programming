#include<iostream>



using namespace std;

string ans(int x, int y){
    if(x % 2 == 1 && y % 2 == 1)
        return "HI";
    else
        return "TAK";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;
        cout << ans(x, y) << '\n';
    }

    return 0;
}

