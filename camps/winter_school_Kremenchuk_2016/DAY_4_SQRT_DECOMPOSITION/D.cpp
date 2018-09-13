#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const static int SQRT = 316;

struct SQRT_DEC
{
    vector<vector<pair<int,long> > > addToBlocks;
    vector<vector<pair<int,long> > > addToOwners;
    vector<int> owners;

    vector<vector<int> > owners_info;

    int n,m;


    SQRT_DEC(istream & in)
    {
        cin >> n >> m;
        owners.assign(m,0);
        addToBlocks.assign((m-1)/SQRT + 1, vector<pair<int,long> >(1,{0,0}));
        addToOwners.assign(n,vector<pair<int,long> >(1,{0,0}));
        owners.assign(m, 0);
        owners_info.assign(n, vector<int>(0));

        for(int i = 0; i<m; i++)
        {
            cin >> owners[i];
            owners[i]--;
            owners_info[owners[i]].push_back(i);
        }
        for(auto & i : owners_info)
        {
            sort(i.begin(), i.end());
        }
        for(auto & i : addToBlocks)
            i.assign(1, {0,0});
    }

    void add(int l,int r, long val, int id)
    {
        for(int i = l; i<=r;)
        {
            if(i%SQRT || i+SQRT>r+1)
            {
                if(addToOwners[owners[i]].rbegin()->first == id)
                {
                    addToOwners[owners[i]].rbegin()->second += val;
                }
                else
                {
                    addToOwners[owners[i]].push_back({id, addToOwners[owners[i]].rbegin()->second + val});
                }
                i++;
            }
            else
            {
                addToBlocks[i/SQRT].push_back({id, addToBlocks[i/SQRT].rbegin()->second + val});
                i+=SQRT;
            }
        }
    }

    long getCountForId(int owner_id, int step)
    {
        long ans = 0;
        for(int i = 0; i<(int)addToBlocks.size(); i++)
        {
            int count_of_stations = lower_bound(owners_info[owner_id].begin(), owners_info[owner_id].end(),(i+1)*SQRT)-
                                    lower_bound(owners_info[owner_id].begin(), owners_info[owner_id].end(),i*SQRT);
                ans+=count_of_stations*((upper_bound(addToBlocks[i].begin(), addToBlocks[i].end(), make_pair(step + 1,0L)) - 1)->second);
        }
        ans+=(lower_bound(addToOwners[owner_id].begin(), addToOwners[owner_id].end(), make_pair(step+1, 0L)) - 1)->second;

        return ans;
    }

    int get_minimal_for_owner(int owner_id, int needMinimum, int maxStep)
    {

        int l = 0, r = maxStep+1;
         if(getCountForId(owner_id,maxStep) < needMinimum)
            return -1;

        while(l+1<r)
        {
            int mid = (l+r-1)/2 + 1;
            if(getCountForId(owner_id, mid) < needMinimum)
                l = mid;
            else
                r = mid;
        }
        return r;
    }

};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SQRT_DEC SD(cin);

    vector<int> need(SD.n);
    for(auto & i : need)
        cin >> i;
    int q;
    cin >> q;

    for(int i = 1; i<=q; i++)
    {
        int l,r,a;
        cin >> l >> r >> a;

        if(l<=r)
            SD.add(l-1,r-1,a,i);
        else
        {
            SD.add(l-1,SD.m-1, a, i);
            SD.add(0,r-1, a, i);
        }
    }
    for(int i = 0; i<SD.n; i++)
    {
        cout << SD.get_minimal_for_owner(i, need[i], q+1) << '\n';
    }


    return 0;
}

