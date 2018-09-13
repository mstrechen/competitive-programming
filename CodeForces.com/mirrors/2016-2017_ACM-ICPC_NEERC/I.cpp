#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

struct comp
{
    bool operator ()(const pair<int,int> & a,const pair<int,int> & b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        else
            return a.first<b.first;
    }
};
void makeLess(pair<int,int> key, map<pair<int,int>, int, comp> & A)
{
    A[key]--;
    if(A[key] == 0)
        A.erase(key);
}

bool compp(pair<int,int> a, pair<int,int> b)
{
    if(a.first==b.first)
        return a.second>b.second;
    else
        return a.first<b.first;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p[2] = {0,0};
    cin >> n >> p[0] >> p[1];

    vector<pair<int,int>> AP(n,{0,0});

    for(int i = 0; i<n; i++)
        cin >> AP[i].first;
    for(int i = 0; i<n; i++)
        cin >> AP[i].second;

    map<pair<int,int>, int, comp> PrSp[2];

    for(int i = 0; i<n; i++)
    {
        bool toProg = AP[i].first>AP[i].second;
        pair<int,int> currPair = {AP[i].first, AP[i].second};

        if(!toProg)
            swap(currPair.first, currPair.second);
        bool flag = 1;
        while(flag&&(p[toProg]||compp(PrSp[toProg].begin()->first, currPair)))
        {
            PrSp[toProg][currPair]++;
            if(p[toProg])
            {
                flag = 0;
                p[toProg]--;
            }
            else
            {
                currPair = PrSp[toProg].begin()->first;
                swap(currPair.first, currPair.second);
                makeLess(currPair,PrSp[toProg]);
                toProg^=1;
            }
        }

    }
    int ans  = 0;
    for(auto i : PrSp[0])
        ans+=i.first.first*i.second;
    for(auto i : PrSp[1])
        ans+=i.first.first*i.second;

    cout << ans;


    return 0;
}
