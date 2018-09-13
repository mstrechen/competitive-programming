#include<iostream>
#include<set>
#include<cmath>
#include<vector>

using namespace std;

int abs(int a){
    if(a < 0)
        return -a;
    return a;
}
double abs(double a){
    if(a < 0)
        return -a;
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
    double R = r;
    r *= 2;
    cout.precision(10);
    cout << (fixed);

    vector<pair<int, double> > a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        double y = R;
        for(auto & i : a)
            if(abs(i.first - x) <= r){
                y = max(y, i.second + sqrt(r*r - (i.first - x)*(i.first - x)));
            }
        a.push_back({x, y});
        cout << y << ' ';
    }


    return 0;
}
