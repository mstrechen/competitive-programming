#include<iostream>
#include<vector>


using namespace std;

void rec(int l, int r, vector<int> & positions, long long & ans, vector<int> & maxes, vector<int> & mins)
{
    if (l == r)
    {
        ans++;
        return;
    }

    int mid = (l+r)/2;

    maxes[mid] = positions[mid];
    maxes[mid+1] = positions[mid+1];
    mins[mid] = positions[mid];
    mins[mid+1] = positions[mid+1];

    for(int i = mid-1; i>=l; i--)
    {
        mins[i] = min(mins[i+1], positions[i]);
        maxes[i] = max(maxes[i+1], positions[i]);
    }
    for(int i = mid+2; i<=r; i++)
    {
        mins[i] = min(mins[i-1], positions[i]);
        maxes[i] = max(maxes[i-1], positions[i]);
    }




    for(int i = mid + 1; i <= r; ++i)
    {
        int L =  i - (maxes[i] - mins[i]);
        if(L >= l && L <= mid && mins[L] > mins[i] && maxes[L] < maxes[i])
            ans++;
    }
    for(int i = mid; i >= l; --i)
    {
        int R = i + maxes[i] - mins[i] ;
        if(R >= mid + 1 && R<= r && mins[R] > mins[i] && maxes[R] < maxes[i])
            ans++;
    }



    {
        int cur = mid + 1;
        for(int i = mid; i >= l; --i)
        {
            while(cur <= r && Lmax[i] > Rmax[cur])
                ++cur;
            P1[i] = cur;
        }
    }

    cur = r;

    for(int i = l; i <= mid; ++i)
    {
        while(cur >= mid + 1 && Lmin[i] > Rmin[cur])
            --cur;
        P2[i] = cur;
        if(P2[i] >= P1[i])
        {
            q1[P1[i]].push_back(Lmin[i] - i + base);
            q2[P2[i]].push_back(Lmin[i] - i + base);
        }
    }
    for(int i = mid + 1; i <= r; ++i)
    {
        for(int j = 0; j < q1[i].size(); ++j)
            ans -= cnt[q1[i][j]];
        ++cnt[Rmax[i] - i + base];
        for(int j = 0; j < q2[i].size(); ++j)
            ans += cnt[q2[i][j]];
    }

    cur = mid;
    for(int i = mid + 1; i <= r; ++i)
    {
        while(cur >= l && Rmax[i] > Lmax[cur])
            --cur;
        P1[i] = cur;
    }
    cur = l;

    for(int i = r; i >= mid + 1; --i)
    {
        while(cur <= mid && Rmin[i] > Lmin[cur])
            ++cur;
        P2[i] = cur;
        if(P2[i] <= P1[i])
        {
            q1[P1[i]].push_back(Rmin[i] + i + base);
            q2[P2[i]].push_back(Rmin[i] + i + base);
        }
    }
    for(int i = mid; i >= l; --i)
    {
        for(int j = 0; j < q1[i].size(); ++j)
            ans -= cnt[q1[i][j]];
        ++cnt[Lmax[i] + i + base];
        for(int j = 0; j < q2[i].size(); ++j)
            ans += cnt[q2[i][j]];
    }

    for(int i = l; i <= r; ++i)
        q1[i].clear(), q2[i].clear();

	rec(l, mid,     positions, ans,maxes, mins);
	rec(mid + 1, r, positions, ans, maxes, mins);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long ans = 0;
    int n;
    cin >> n;

    vector<int> nums(n),maxes(n), mins(n);

    for(auto & i : nums)
        cin >> i;

    rec(0, (int)nums.size()-1, nums, ans, maxes, mins);

	return 0;
}
