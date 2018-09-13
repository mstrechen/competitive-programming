#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

using point = pair<int, int>;
using vector2d = pair<int, int>;

vector2d operator - (const point & a, const point & b){
    return {a.first - b.first, a.second - b.second};
}

int operator * (const vector2d & a, const vector2d & b){
    return a.first*b.second - a.second*b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<point> p(n);

    for(auto & i : p)
        cin >> i.first >> i.second;
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());

    vector<point> res;
    res.push_back(*max_element(p.begin(),p.end()) );
    set<point> were(res.begin(), res.end());

    do{
        res.push_back(*max_element(p.begin(), p.end(),
                                   [res](const point & a, const point & b){
                                        return (a - res.back())*(b - res.back()) > 0 || a == res.back();
                                   }  ) );
        were.insert(res.back());
    }
    while(res.back() != res.front());

    int ans = 0;
    for(int i = 1; i < (int)res.size(); i++){
        ans += (res[i].first - res[i-1].first)*(res[i].second + res[i-1].second);
    }

    cout << round(ans/2.0);




    return 0;
}
