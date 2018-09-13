#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;


long long timeToGo(long long effect1, long long effect2, long long n, long long x)
{
    return max(0LL, n-effect2)*effect1;
}

bool comp(pair<long long,long long> a, pair<long long,long long> b)
{
    return a.second<b.second;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    long long x, s;

    cin >> n >> m >> k;
    cin >> x >> s;

    vector<pair<long long,long long > > firstType(m,{0,0}), A, B;
    vector<long long> secondType(k, 0);
    vector<long long> secondType1(k, 0);


    for(int i = 0; i<m; i++ )
    {
        cin >> firstType[i].first;
    }
    for(int i = 0; i<m; i++ )
    {
        cin >> firstType[i].second;
    }
    for(int i = 0; i<k; i++ )
    {
        cin >> secondType1[i];
    }
    for(int i = 0; i<k; i++ )
    {
        cin >> secondType[i];
    }
    firstType.push_back({x,0});

    reverse(secondType.begin(),secondType.end());
    reverse(secondType1.begin(),secondType1.end());
    secondType.push_back(0);
    secondType1.push_back(0);

    long long ans = x*n;
    for(auto i : firstType)
    {
        auto it = upper_bound(secondType.begin(),secondType.end(), s-i.second, greater<long long>());
        if(it!=secondType.begin())
        {
            it--;
            if(*it!=s-i.second)
                it++;
        }
        if(it!=secondType.end())
        {
            ans = min(ans, timeToGo(i.first, secondType1[it-secondType.begin()], n, x));
        }
    }
    cout << ans;



    return 0;
}
