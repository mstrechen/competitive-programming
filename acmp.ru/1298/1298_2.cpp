#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> inp(n), prev(n);
    
    for(auto& i : inp) cin >> i;
    
    vector<pair<int,int> > dp;
    
    int maxAns = -1, maxI = -1;
    
    for(int i = 0; i<n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), make_pair(inp[i],0));
        if(it==dp.end())
        {
            dp.push_back({inp[i],i});
            it = dp.end() - 1;
        }
        
        if(it==dp.begin())
        {
            if(it->first!=inp[i])
                *it = {inp[i], i};
            prev[i] = -1;
        }
        else
        {
            if(it->first!=inp[i])
                *it = {inp[i], i};
            
            prev[i] = (it-1)->second;
        }
        if(it-dp.begin() > maxAns)
        {
            maxAns = it-dp.begin();
            maxI = i;
        }
    }
    
    vector<int> res;
    for(int i = maxI; i!=-1; i = prev[i])
        res.push_back(inp[i]);
    
    cout << maxAns + 1 << '\n';
    
    for(int i = maxAns; i>=0; i--)
        cout << res[i] << ' ';
    
	
	return 0;
}