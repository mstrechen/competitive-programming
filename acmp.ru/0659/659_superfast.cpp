#include<iostream>
#include<cassert>
#include<bitset>
#include<vector>

using namespace std;

const int HALF = 12;
const int HALF_MASK_COUNT = (1 << 12);
const int HALF_MASK = (1 << 12) - 1;

int main(){
    int popcount[HALF_MASK_COUNT] = {};
    for(int i = 0; i < HALF_MASK_COUNT; i++){
        popcount[i] = __builtin_popcount(i);
    }

    int friends[24] = {};

    int n, k, m;
    cin >> n >> k >> m;

    int maxAns = -1;
    int maxAnsMask = -1;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        friends[--a] |= 1 << --b;
    }

    for(int mask = (1 << n) - 1 ; mask >= 0; --mask)
    if(popcount[mask & HALF_MASK] + popcount[mask >> HALF] == k){
        int currentAns = 0;

        for(int i = 0; i < n; i++){
            int friendsCode = (~(mask << (31 - i) >> 31) ^ mask) & friends[i];
            currentAns += popcount[friendsCode >> HALF] + popcount[friendsCode & HALF_MASK];
        }

        if(currentAns > maxAns)
        {
            maxAns = currentAns;
            maxAnsMask = mask;
        }
    }
    assert(maxAnsMask != -1);
    for(int i = 0; i < n; i++)
        if((maxAnsMask >> i)&1)
            cout << i+1 << ' ';

    return 0;
}
