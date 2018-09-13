#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<string> > s(n, vector<string>(m, string(k, '0')));

    for(int _i = 0; _i < k; _i++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> s[i][j][_i];
            }

    set<string> ss;
    for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                ss.insert(s[i][j]);
            }

    cout << ss.size();


    return 0;
}
