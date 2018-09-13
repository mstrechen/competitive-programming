#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>


using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.second>b.second;
}

int getAns(vector<pair<int,int>>::iterator be, vector<pair<int,int>>::iterator en, int v)
{
    sort(be,en,[](pair<int,int> a, pair<int,int> b){return a.second>b.second;});

    int ans = 0;
    int currV = 0;
    while(currV<v&&be!=en)
    {
        currV+=be->second;
        be++;
        ans++;
    }
    if(currV<v)
        return -100500;
    else
        return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int,int> > bottles(n,{0,0});

    for(int i = 0; i<n; i++)
        cin >> bottles[i].first;
    for(int i = 0; i<n; i++)
        cin >> bottles[i].second;


    int summV = accumulate(bottles.begin(),bottles.end(), 0, [](int a, pair<int,int>){})



    return 0;
}
