#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

const long long KEY = -100500;

long long merge_with_count(int l, int r, int L, int R, vector<int> & a, vector<int> & b){

    if(r - l == 1)
        return 0;
    auto mid = (r+l)/2;
    auto MID = (R + L)/2;
    long long ans = merge_with_count(l, mid, L, MID, a, b) +
                    merge_with_count(mid, r, MID, R, a,b );

    copy(a.begin() + l, a.begin() + r, b.begin() + L);

    auto IT = l;
    auto _l = L, _r = MID;
    for(; _l != MID && _r != R; ){
        if(b[_l] < b[_r]){
            a[IT++] = b[_l++];
        } else {
            ans += MID - _l;
            a[IT++] = b[_r++];
        }
    }
    while(_l != MID)
        a[IT++] = b[_l++];
    while(_r != R)
        a[IT++] = b[_r++];

    return ans;
}

long long countInversions(vector<int> & nums){
    vector<int> toCopy(nums.size());
    return merge_with_count(0, nums.size(), 0, nums.size(), nums, toCopy);
}

int countSwaps(vector<int> &nums, long long & inversions){
    vector<int> sortedNums(nums.size());
    unordered_map<int, int> indexes;
    for(int i=0; i<nums.size(); i++) {
        sortedNums[i] = nums[i];
        indexes[nums[i]] = i;
    }

    inversions = countInversions(sortedNums);
    int sum = 0;
    for(int i = 0; i<nums.size(); i++){
        int current = nums[i];
        if(current == KEY)
            continue;
        int chainSum = 0;
        int next = sortedNums[indexes[current]];
        while(next != current){
            nums[indexes[next]] = KEY;
            chainSum++;
            next = sortedNums[indexes[next]];
        }
        nums[indexes[current]] = KEY;
        sum += chainSum;
    }
    return sum;
}


int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    long long inversions;
    int swaps = countSwaps(nums, inversions);
    cout<<swaps<<'\n'<<inversions;
    return 0;
}
