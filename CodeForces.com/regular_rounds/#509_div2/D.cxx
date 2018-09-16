#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    
    int n, h;
    cin >> n >> h;
    vector<int> points;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        points.push_back(x);
        points.push_back(y);
    }
    points.push_back(0);
    sort(points.begin(), points.end());
    

    vector<int> delta_h;
    int level = 0;
    for(int i = 0; i < 2 * n; i++){
        if(i & 1)
            delta_h.push_back(level);
        else 
            level += points[i + 1] - points[i],
            delta_h.push_back(level);
    }
    int maxans = h;
    
    for(auto it = delta_h.begin(); it != delta_h.end(); it++){
        auto it_next = lower_bound(it, delta_h.end(), h + *it);
        it_next--;
        int cur_point = points[it - delta_h.begin() + 1];
        int next_point = points[it_next - delta_h.begin() + 1];
        maxans = max(maxans, next_point - cur_point + h - (*it_next - *it));

    }
    cout << maxans;    

    return 0;
}