#include<iostream>
#include<functional>
#include<map>
#include<set>

using namespace std;


map<long long,int> segments_summs;

set<pair<int,int> > segments1;



long long getmax()
{
    return (*segments_summs.rbegin()).first;
}
void makeLess(long long i)
{
    segments_summs[i]--;
    if(segments_summs[i]==0)
        segments_summs.erase(i);
}
long long a[100500];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    segments_summs[a[n]]++;
    segments1.insert({1,n});

    int tmp;
    pair<int,int> s, s1;
    set<pair<int, int> >::iterator it;
    for(int i = 1; i<=n; i++)
    {
        cin >> tmp;
        it = segments1.upper_bound({tmp,1000000000});
        it--;
        s = *it;
        segments1.erase(s);
        makeLess(a[s.second]-a[s.first-1]);
        s1 = {tmp+1, s.second};
        s = {s.first,tmp-1};
        segments1.insert(s);
        segments1.insert(s1);
        segments_summs[a[s.second]-a[s.first-1]]++;
        segments_summs[a[s1.second]-a[s1.first-1]]++;
        cout << getmax() << '\n';
    }
    return 0;
}
