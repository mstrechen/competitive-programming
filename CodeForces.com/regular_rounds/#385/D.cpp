#include<iostream>
#include<set>
#include<vector>

using namespace std;

set<int> askFor(int size, int offset,  int n, set<int> & ans)
{
    ans.clear();

    for(int i = 0; i<n; i+=size*2)
    {
        for(int j = i+offset*size; j<n&&j<i+offset*size+size; j++)
            ans.insert(j);
    }
    if(ans.size())
    {
        cout << ans.size() << endl;
        for(auto i : ans)
            cout << i+1 << ' ';
        cout << endl;
    }
    return ans;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    vector<int> minimums(n, 2*1000*1000*1000);
    set<int> tmp;

    for(int sz = 1; sz<n; sz*=2)
    {
        askFor(sz, 0, n,tmp);

        if(tmp.size())
            for(int i = 0; i<n; i++)
            {
                int x;
                cin >> x;
                if(tmp.count(i)==0)
                    minimums[i] = min(minimums[i], x);
            }
        askFor(sz, 1, n,tmp);

        if(tmp.size())
            for(int i = 0; i<n; i++)
            {
                int x;
                cin >> x;
                if(tmp.count(i)==0)
                    minimums[i] = min(minimums[i], x);
            }
    }
    cout << -1 << endl;

    for(int i = 0; i<n; i++)
        cout << minimums[i] << ' ';
    cout << endl;

    return 0;
}

