#include<iostream>
#include<set>

using namespace std;

set<char> a = {'a', 'o', 'u', 'i', 'e', 'n'};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++)
        if(!a.count(s[i]))
            if(i == (int)s.size() - 1 || ( a.count(s[i + 1]) == 0 || s[i + 1] == 'n')){
                cout << "NO";
                return 0;
            }
    cout << "YES";

    return 0;
}