#include<iostream>
#include<set>
#include<vector>
#include<functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int> > bets(n);
    vector<int> maxBets(n);

    for(int i = 0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        bets[a].push_back(b);
        maxBets[a] = max(maxBets[a], b);
    }

    set<pair<int,int>, greater<pair<int,int> > > currentBets;

    for(int i = 0; i<n; i++)
        if(maxBets[i]!=0)
            currentBets.insert({maxBets[i],i});

    vector<int> deleted;

    int q;

    cin >> q;

    for(int i = 0; i<q; i++)
    {
        int k;
        cin >> k;
        deleted.resize(k);
        for(auto & i : deleted)
        {
            cin >> i;
            i--;
        }
        for(auto i : deleted)
            currentBets.erase({maxBets[i], i});

        if(currentBets.size() == 0)
        {
            cout << "0 0\n";
        }
        else
        if(currentBets.size() == 1)
        {
            int num = currentBets.begin()->second;
            cout << num + 1 << ' ' << bets[num][0] << '\n';
        }
        else
        {
            int num = currentBets.begin()->second;

            cout << num + 1 << ' ' << *lower_bound(bets[num].begin(), bets[num].end(), (++currentBets.begin())->first) << '\n';
        }

        for(auto i : deleted)
            if(maxBets[i]!=0)
                currentBets.insert({maxBets[i], i});
    }


    return 0;
}
