#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

struct segment_tree{
    int size;
    vector<int> mins, added;

    segment_tree(int n) : size(n){
        while(size & (size - 1))
            size &= size - 1;
        if(size != n)
            size *= 2;
        mins.resize(size * 2);
        added.assign(size * 2, 0);
        for(int i = 0; i < n; i++)
            mins[i + size] = 0;
        for(int i = n; i < size; i++)
            mins[i + size] = 1e9;

        for(int i = size - 1; i > 0; i--)
            mins[i] = min(mins[i*2], mins[i*2 + 1]);
    }

    int add(int l, int r, int min_l, int max_r, int i){
        if(l > r)
            return mins[i] + added[i];
        if(l == min_l && r == max_r)
            return mins[i] + (++added[i]);

        int mid = (min_l + max_r)/2;
        return (mins[i] = min(add(l,              min(r, mid), min_l, mid,   i*2),
                             add(max(l, mid + 1), r,           mid+1, max_r, i*2 + 1)))
                          + added[i];
    }

    int get(int l, int r, int min_l, int max_r, int i){
        if(l > r)
            return 1e9;
        if(l == min_l && r == max_r)
            return mins[i] + added[i];

        int mid = (min_l + max_r)/2;

        return min(get(l,               min(r, mid), min_l, mid,   i*2),
                   get(max(l, mid + 1), r,           mid+1, max_r, i*2 + 1))
                   + added[i];
    }

    void add(int l, int r){
        add(l + 1, r + 1, 1, size, 1);
    }

    int get(int l, int r){
        return get(l + 1, r + 1, 1, size, 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int> > segs(n);
    vector<int> possible_elements;
    possible_elements.reserve(4*n);
    for(auto & i : segs){
        cin >> i.first >> i.second;
        possible_elements.push_back(i.first);
        possible_elements.push_back(i.first + 1);
        possible_elements.push_back(i.first - 1);
        possible_elements.push_back(i.second);
        possible_elements.push_back(i.second - 1);
        possible_elements.push_back(i.second + 1);
    }
    sort(possible_elements.begin(), possible_elements.end());
    auto new_end = unique(possible_elements.begin(), possible_elements.end());
    possible_elements.erase(new_end, possible_elements.end());

    segment_tree st(possible_elements.size() + 1);
    for(auto & i : segs){
        st.add(lower_bound(possible_elements.begin(), possible_elements.end(), i.first)
               - possible_elements.begin(),
               lower_bound(possible_elements.begin(), possible_elements.end(), i.second)
               - possible_elements.begin());
    }
    for(int i = 0; i < (int)segs.size(); i++){
        if(st.get(lower_bound(possible_elements.begin(), possible_elements.end(), segs[i].first)
                  - possible_elements.begin(),
                  lower_bound(possible_elements.begin(), possible_elements.end(), segs[i].second)
                  - possible_elements.begin()) > 1){
                    cout << i+1;
                    return 0;
                  }
    }

    cout << -1;


    return 0;
}
