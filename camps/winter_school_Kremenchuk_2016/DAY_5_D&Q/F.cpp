#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>

using namespace std;

void rec(int l, int r, vector<pair<int,int> > & points, set<pair<int,int> > & ans, set<int> & trash)
{
    if(l>=r)
        return;
    if(l+1 == r)
    {
        ans.insert({points[l].first,points[r].second});
        return;
    }

    int xMid = points[(l+r)/2].first;

    trash.clear();
    for(int i = l; i<=r; i++)
        if(points[i].first!=xMid)
            trash.insert(points[i].second);
    for(int i = l; i<=r; i++)
        if(points[i].first==xMid)
            trash.erase(points[i].second);


    for(auto i : trash)
        ans.insert({xMid,i});

    rec(l,(l+r)/2, points, ans, trash);
    rec((l+r)/2+1, r, points, ans, trash);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int> > points(n);
    set<pair<int,int> > ans;

    set<int> trash;

    for(auto & i : points)
        cin >> i.first >> i.second;

    sort(points.begin(), points.end());
    rec(0, n-1, points, ans, trash);

    cout << ans.size() << '\n';

    for(auto & i : ans)
        cout << i.first << ' ' << i.second << '\n';

    return 0;
}
