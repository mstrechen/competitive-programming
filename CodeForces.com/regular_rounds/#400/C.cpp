#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    map<long long, int> cnt;
    vector<long long> step;

    int n, k;

    cin >> n >> k;

    if(abs(k)==1)
    {
        step.push_back(k);
        if(k==-1)
            step.push_back(1);
    }
    else
    {
        long long cur = 1;
        while(cur<=MAXN)
        {
            step.push_back(cur);
            cur*=k;
        }
    }


    long long pref = 0;
    long long ans = 0;
    cnt[0] = 1;
    for(int i = 0; i<n; i++)
    {
        int tmp;
        cin >> tmp;

        pref+=tmp;

        for(auto x : step)
            if(cnt.count(pref-x))
            {
                ans+=cnt[pref-x];
            }

        cnt[pref]++;
    }

    cout << ans;

    return 0;
}
