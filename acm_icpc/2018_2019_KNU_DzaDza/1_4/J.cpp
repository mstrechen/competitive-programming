#include<iostream>
#include<algorithm>
#include<set>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    multiset<int> s;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.insert(-x);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(s.lower_bound(-x) != s.end())
            s.erase(s.lower_bound(-x));
        cout << n - s.size() << '\n';
    }
    return 0;
}
