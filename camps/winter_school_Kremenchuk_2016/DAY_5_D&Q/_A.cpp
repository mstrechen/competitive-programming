#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int> >,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;


const int oo = 2*1000*1000*1000;


struct SparseTable
{
    vector<vector<pair<int,int> > > maximums;
    int _size;

    SparseTable(const vector<int> & numbers)
    {
        _size = numbers.size();
        while(_size&(_size-1))
        {
            _size&=(_size-1);
        }
        _size = __builtin_ffs(_size);


        maximums.assign(_size,vector<pair<int,int> >(numbers.size()));

        for(int i = 0; i<(int)numbers.size(); i++)
        {
            maximums[0][i] = {numbers[i], i};
        }
        for(int _i = 1; _i<_size; _i++)
        {
            for(int i = 0; i<(int)numbers.size(); i++)
            {
                maximums[_i][i] = max(maximums[_i-1][i],
                                      maximums[_i-1][min(i + (1 << (_i-1)), (int)numbers.size()-1)]);
            }
        }
    }

    pair<int,int> get(int l, int r) const
    {
        int sizeOfQ = r-l+1;

        while(sizeOfQ&(sizeOfQ-1))
            sizeOfQ&=(sizeOfQ-1);

        sizeOfQ = __builtin_ffs(sizeOfQ) - 1;

        if(l+(1<<sizeOfQ)-1 == r)
        {
            return maximums[sizeOfQ][l];
        }
        else
           return max(maximums[sizeOfQ][l], maximums[sizeOfQ][r - (1<<sizeOfQ) + 1]);
    }
};


void makeDaShit(int l, int r,  const vector<int> & all, const SparseTable & ST, vector<pair<pair<int,int>,int> > & queries)
{
    if(l>=r)
        return;

    auto maxEl = ST.get(l,r);

    int maxIndex = maxEl.second;
    int maxElement = maxEl.first;

    if(maxIndex - l < r - maxIndex)
    {
        for(int i = l; i<maxIndex; i++)
        {
            queries.push_back({{maxIndex+1, r},maxElement/all[i]});
        }
    }
    else
    {
        for(int i = maxIndex+1; i<=r; i++)
            queries.push_back({{l, maxIndex-1},maxElement/all[i]});
    }
    queries.push_back({{l,maxIndex-1}, 1});
    queries.push_back({{maxIndex+1,r}, 1});

    makeDaShit(l, maxIndex-1,all, ST, queries);
    makeDaShit(maxIndex+1, r, all, ST, queries);
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n;

    vector<int> numbers(n);


    for(auto & i : numbers)
        cin >> i;

    SparseTable ST(numbers);

    vector<pair<pair<int,int>,int> > queries;

    makeDaShit(0, numbers.size()-1, numbers, ST, queries);


    long long answer = 0;
    vector<vector<int> > events(n+1);

    for(auto & i : queries)
    {
        events[i.first.first].push_back(-i.second - 1);
        events[i.first.second + 1].push_back(i.second);
    }

    int curr_id = 0;

    ordered_set prevNumbers;

    for(int _i = 0; _i<=n; _i++)
    {
        for(auto & i : events[_i])
        {
            if(i>=0)
            {
                answer+=prevNumbers.order_of_key({i,0});
            }
            else
            {
                answer-=prevNumbers.order_of_key({-(i+1),0});
            }
        }
        if(_i<n)
           prevNumbers.insert({numbers[_i], --curr_id});
    }
	
    cout << answer;

    return 0;
}
