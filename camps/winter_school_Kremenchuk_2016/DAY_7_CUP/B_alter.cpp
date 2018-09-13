#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

bool rec(int toLock, int places, vector<int> & res)
{
    if(toLock<places || places < 1)
        return false;
    if(places==1)
    {
        res.push_back(toLock);
        return true;
    }
    bool resB = rec(toLock/2, places/2, res);
         resB&= rec(toLock - toLock/2, places - places/2, res);

    return  resB;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int sum = n;

    vector<int> res;

    if(n<k || k==1)
    {
        cout << -1;
        return 0;
    }

    vector<int> ans(k, 0);

    vector<pair<int,int> > add;

    int countOfAdded = 0;

    for(int i = (1<<20); i>1; i/=2)
    {
        int count = min(n/i, k/2);
        int l = 0, r = count+1;

        while(l+1<r)
        {
            int mid = (l+r)/2;
            if(countOfAdded + (n-i*mid) + 2*mid >=k)
                l = mid;
            else
                r = mid;
        }
        n-=i*l;
        countOfAdded+=l*2;
        if(l>0)
            add.push_back({i/2, l*2});
    }

    int _i = 0;

    for(auto i : add)
    {
        for(int j = 0; j<i.second; j++)
        {
            ans[_i]+=i.first;
            _i = (_i+1)%k;
        }
    }

    int myXor = 0;
    for(auto i : ans)
    {
        myXor^=i;
        sum-=i;
    }
    if(myXor!=0 || sum!=0)
    {
        cout << -1;
        return 0;
    }

    for(auto i : ans)
        cout << i << ' ';




    return 0;
}



