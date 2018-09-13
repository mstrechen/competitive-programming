#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(vector<string> & a, const vector<pair<int, int> > & howto, const string & instruction){
    int x = 0, y = 0;
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < a[i].size(); j++)
            if(a[i][j] == 'S')
                x = i, y = j;
    for(auto i : instruction){
        x += howto[i - '0'].first;
        y += howto[i - '0'].second;
        if(a[x][y] == '#')
            return 0;
        if(a[x][y] == 'E')
            return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> a(n + 2);
    string instruction;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = '#' + a[i] + '#';
    }
    a[0] = string(m + 2, '#');
    a[n+1] = string(m + 2, '#');

    cin >> instruction;
    int ans = 0;
    vector<pair<int, int> > perm = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    sort(perm.begin(), perm.end());
    do{
        ans += check(a, perm, instruction);

    }while(next_permutation(perm.begin(), perm.end()));

    cout << ans;
    return 0;
}
