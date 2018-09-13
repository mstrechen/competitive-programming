#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

int getSeg(vector<pair<int,int>>::iterator fst, vector<pair<int,int>>::iterator lst)
{
    int be = fst->first;
    int ans = 0;
    while(fst!=lst&&fst->first==be)
    {
        ans++;
        fst++;
    }
    return ans;
}

void makeLess(vector<pair<int,int> > & cur, vector<vector<int> > & res)
{
    int n = cur.size();
    vector<int> curres(n,0);
    int curSeg = getSeg(cur.begin(), cur.end());

    if(curSeg==1)
    {
        for(int i = 0; i<2; i++)
        {
            curres[cur[i].second]++;
            cur[i].first-=(bool)cur[i].first;
        }
    }
    else
    {
        if(curSeg!=6)
        {
            for(int i = 0; i<min(curSeg,5); i++)
            {
                curres[cur[i].second]++;
                cur[i].first-=(bool)cur[i].first;
            }
        }
        else
        {
            for(int i = 0; i<3; i++)
            {
                curres[cur[i].second]++;
                cur[i].first-=(bool)cur[i].first;
            }
        }
    }

    res.push_back(curres);

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int> > res;
    vector<pair<int,int> > current;

    int n;
    cin >> n;
    current.assign(n,{0,0});
    for(int i = 0; i<n; i++)
    {
        cin >> current[i].first;
        current[i].second = i;
    }
    sort(current.begin(), current.end(), greater<pair<int,int> >());
    while(current.begin()->first!=(current.end()-1)->first)
    {
        makeLess(current, res);

        sort(current.begin(), current.end(), greater<pair<int,int>>());
    }
    cout << (current.begin()->first) <<'\n';
    cout << res.size() <<'\n';
    for(auto i : res)
    {
        for(auto j : i)
            cout << j;
        cout << '\n';
    }
    return 0;
}
