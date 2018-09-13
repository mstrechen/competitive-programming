#include<iostream>
#include<string>
#include<numeric>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int a_cnt = accumulate(s.begin(), s.end(), 0, 
    [](int cnt, char c){
        return cnt + (c == 'a');
    });
    int b_cnt = accumulate(s.begin(), s.end(), 0, 
    [](int cnt, char c){
        return cnt + (c == 'b');
    });
    int c_cnt = accumulate(s.begin(), s.end(), 0, 
    [](int cnt, char c){
        return cnt + (c == 'c');
    });
    if(a_cnt == 0 || b_cnt == 0 || (a_cnt != c_cnt && b_cnt != c_cnt)){
        cout << "NO";
        return 0;
    }

    int state = 'a' - 1;
    for(auto & i : s){
        if(state > i){
            cout << "NO";
            return 0;
        }
        state = i;
    }
    cout << "YES";


    return 0;
}