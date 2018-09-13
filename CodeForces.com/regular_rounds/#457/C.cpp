#include<iostream>
#include<set>

using namespace std;

bool isPrime(int x){
    if(x == 1)
        return 0;
    if(x % 2 == 0)
        return x == 2;
    for(int i = 3; i * i <= x; i+=2)
        if(x % i == 0)
            return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin >> n >> m;

    int wayW = n - 1;
    while(!isPrime(wayW))
        wayW++;

    set<pair<int, int> > e;

    cout << wayW << ' ' << wayW << '\n';
    for(int i = 1; i < n; i++){
        int s = wayW / (n - i);
        cout << i << ' ' << i + 1 << ' '<<  s << '\n';
        e.insert({i, i + 1});
        wayW -= s;
    }
    m -= n - 1;
    for(int i = 1; i <= n && m; i++)
        for(int j = i + 1; j <= n && m; j++){
            if(!e.count({i, j})){
                cout << i << ' ' << j << ' ' << 1000*1000*1000 << '\n';
                m--;
            }
        }

    return 0;
}
