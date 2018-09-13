#include <iostream>
#include <functional>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

pair<long long,long long> a[300300];

void makeLess(long long key, map<long long, int> & A)
{
    A[key]--;
    if(!A[key])
        A.erase(key);
}

long long min(long long a, long long b)
{
    return a>b?b:a;
}

int main(){
	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    long long t,w;

    cin >> t >> w;

    n--;
    for(int i = 0; i<n; i++)
        cin >> a[i].first >> a[i].second;


    sort(a,a+n, greater<pair<long long, long long> >());

    int _i = 0;
    map<long long, int> greater_need;

    long long cnt = 0;
    while(_i<n&&a[_i].first>t)
    {
        greater_need[a[_i].second-a[_i].first+1]++;
        _i++;
        cnt++;
    }

    long long maxAns = cnt;

    pair<long long, long long> tmp;

    while(t>0&&cnt)
    {
        tmp = *greater_need.begin();
        if(t>=tmp.first)
        {
            t-=tmp.first;
            makeLess(tmp.first, greater_need);
            cnt--;
            while(_i<n&&a[_i].first>t)
            {
                greater_need[a[_i].second-a[_i].first+1]++;
                _i++;
                cnt++;
            }
            maxAns = min(cnt,maxAns);
        }
        else
            t = 0;
    }

    cout << maxAns+1;
    return 0;
}
