#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<functional>
#include<set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    //problems, time, id
    vector<tuple<int, int, int> > problems(n);
    int j = 0;
    for(auto & i : problems)
        j++,
        cin >> get<0>(i) >> get<1>(i),
        get<2>(i) = j,
        get<1>(i);

    sort(problems.begin(), problems.end(),greater<tuple<int, int, int> >());
    // time, problems, id
    set<tuple<int, int, int> , greater<tuple<int, int, int> > > prb;
    int maxans = 0, curans = 0;
    int max_cnt = 1000*1000*1000;
    int cur_time = 0;
    for(auto & i : problems){
        max_cnt = min(get<0>(i), max_cnt);

        prb.emplace(get<1>(i),
                     get<0>(i),
                     get<2>(i));
        cur_time += get<1>(i);

        while(cur_time > t || max_cnt < prb.size()){
            auto it = prb.begin();
            cur_time -= get<0>(*it);
            prb.erase(it);
        }

        curans = (int)prb.size();
        if(curans > maxans)
            maxans = curans;

    }
    cout << maxans << '\n';
    prb.clear();
    curans = 0, max_cnt = 1000*1000*1000, cur_time = 0;
    for(auto & i : problems){
        max_cnt = min(get<0>(i), max_cnt);

        prb.emplace(get<1>(i),
                     get<0>(i),
                     get<2>(i));
        cur_time += get<1>(i);

        while(cur_time > t || max_cnt < prb.size()){
            auto it = prb.begin();
            cur_time -= get<0>(*it);
            prb.erase(it);
        }
        curans = (int)prb.size();
        if(curans == maxans){
            cout << prb.size() << '\n';
            for(auto & i : prb)
                cout << get<2>(i) << ' ';
            return 0;
        }

    }


    return 0;
}
