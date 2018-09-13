#include<iostream>

using namespace std;

int COORD = 1000*1000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a_prev, a, min_ans;
    cin >> a;
    if(n == 1){
        cout << min(a - 1, COORD - a);
        return 0;
    } else {
        min_ans = COORD - a;
        for(int i = 1; i < n; i++){
            a_prev = a;
            cin >> a;
            min_ans = min(min_ans, max(a_prev - 1, COORD - a));
        }
        min_ans = min(min_ans, a - 1);
    }
    cout << min_ans;

    return 0;
}