#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>


using namespace std;


void dfs(int v, vector<int> & used, vector<int> & canSend,
                vector<int> & realId, vector<pair<int,int> > & ans)
{
    used[v] = 1;

    for(int i = v+1; i < (int)used.size() && canSend[v]; i++)
        if(!used[i])
        {
            ans.push_back({realId[v] + 1, realId[i] + 1});
            dfs(i, used, canSend, realId, ans);
            canSend[v]--;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int> > students(n);
    for(int i = 0; i<n; i++)
    {
        cin >> students[i].first;
        students[i].second = i;
    }

    sort(students.begin() + 1, students.end(), greater<pair<int,int> >() );

    vector<int> realId(n), canSend(n), used(n, 0);
    for(int i = 0; i<n; i++)
    {
        realId[i] = students[i].second;
        canSend[i] = students[i].first;
    }

    vector<pair<int,int> > ans;

    dfs(0, used, canSend, realId, ans);

    if((int)ans.size() != n-1)
        cout << -1;
    else
    {
        cout << n-1 << '\n';
        for(auto & i : ans)
            cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}
