#include<iostream>
#include<vector>
#include<set>
#include<functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> arrayToPlay(n, 0);

    for(auto & i : arrayToPlay)
        cin >> i;

    vector<vector<int> > toDo(n+1);

    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        toDo[l-1].push_back(r);
        toDo[r].push_back(-r);
    }


    int ans = 0;

    multiset<int, greater<int> > currentQs;
    for(int i = 0; i<n; i++)
    {
        for(auto j : toDo[i])
        {
            if(j>0)
                currentQs.insert(j);
            else
                currentQs.erase(-j);
        }

        while(arrayToPlay[i]<(int)currentQs.size())
        {
            currentQs.erase(currentQs.begin());
            ans++;
        }
    }
    cout << ans;

    return 0;
}
