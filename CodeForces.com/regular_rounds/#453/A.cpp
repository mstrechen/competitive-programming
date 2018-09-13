#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(n);
    for(auto & i : a)
        cin >> i.first >> i.second;

    if(a[0].first != 0){
        cout << "NO";
        return 0;
    }
    int maxCoord = 0;
    for(auto & i : a){
        if(i.first > maxCoord)
            break;
        maxCoord = max(maxCoord, i.second);
    }
    if(maxCoord < m){
        cout << "NO";
    } else {
        cout << "YES";
    }


    return 0;
}
