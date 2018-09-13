#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

long long sqr(long long x){
    return x*x;
}

long long getdist(pair<int, int> & a, pair<int, int> & b){
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<pair<int, int> > points;
    vector<long long> dists;

    cin >> n;

    points.resize(n);

    for(auto & i : points)
        cin >> i.first >> i.second;

    long long ans = 0, ans_minus = -n;

    sort(points.begin(), points.end());
    for(auto & i : points){
        for(auto & j : points){
            dists.push_back(getdist(i, j));
            if((i.first + j.first)%2 == 0 &&
               (i.second + j.second)%2 == 0 &&
               binary_search(points.begin(), points.end(),
                             make_pair((i.first + j.first)/2,
                              (i.second + j.second)/2)))
                ++ans_minus;
        }

        sort(dists.begin(), dists.end());
        for(auto it = dists.begin(); it != dists.end(); ){
            auto it_end = upper_bound(it, dists.end(), *it);
            ans += (it_end - it)*1LL*(it_end - it - 1);
            it = it_end;
        }

        dists.clear();
    }
    cout << ans/2 - ans_minus/2;

    return 0;
}
