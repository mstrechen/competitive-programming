#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const double MATH_PI = acos(-1);

int sqr(int a){
    return a*a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, n;
    double r;
    cin >> x >> y >> r;
    r *= r;

    vector<double> angles;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x1, y1;
        cin >> x1 >> y1;
        if(sqr(x1 - x) + sqr(y1 - y) <= r){
            angles.push_back(atan2(x1 - x, y1 - y));
        }
    }
    sort(angles.begin(), angles.end());
    n = angles.size();
    for(int i = 0; i < n; i++){
        angles.push_back(angles[i] + 2*MATH_PI);
    }
    angles.push_back(6*MATH_PI);

    int max_ans = 0;
    for(int l = 0, r = 0; l + 1 < (int)angles.size(); l++){
        while(angles[r] - angles[l] <= MATH_PI)
            r++;
        max_ans = max(max_ans, r - l);
    }
    cout << max_ans;
    return 0;
}
