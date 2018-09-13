#include<iostream>
#include<fstream>
#include<vector>
#include<map>

using namespace std;

const int N = 100001;
vector<pair<int, long long>> c[N];

long long a[N];

long long min(long long a, long long b)
{
    return a>b?b:a;
}

pair<int,int> _tmp;
pair<int,int> get(int _i, long long dist, long long minDist)
{
    int ans = 0;
    int cV = 1;
    for(int i = 0; i<c[_i].size(); i++)
    {
        _tmp = get(c[_i][i].first, c[_i][i].second+dist, min(minDist, c[_i][i].second+dist));
        ans+=_tmp.first;
        cV+=_tmp.second;
    }
    if(_i!=0)
    {
        if(dist-minDist>a[_i])
        {
            ans = cV;
        }
    }
    return {ans, cV};
}


int main()
{
    ios::sync_with_stdio(false);
    int n;
    int tmp1, tmp2;
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    for(int i = 1; i<n; i++)
    {
        cin >> tmp1 >> tmp2;
        tmp1--;
        c[tmp1].push_back({i,tmp2});
    }
    cout << get(0, 0, 0).first;
    return 0;
}
