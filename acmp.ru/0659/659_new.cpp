#include<iostream>
#include<cassert>
#include<vector>

using namespace std;
int e[25];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    int maxAns = -1;
    int maxAnsMask = -1;

    int invertedMask = (1 << n) - 1;


    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        e[a] |= 1 << b;
        e[b] |= 1 << a;
    }

    for(int mask = (1 << (n - 1)) - 1 ; mask >= 0; --mask)
    if(__builtin_popcount(mask) == k || __builtin_popcount(mask) == n - k){
        int currentAns = 0;

        for(int i = 0; i < n; i++)
            if((mask >> i) & 1)
                currentAns += __builtin_popcount(mask & e[i]);
            else
                currentAns += __builtin_popcount((invertedMask^mask)&e[i]);

        if(currentAns > maxAns)
        {
            maxAns = currentAns;
            maxAnsMask = mask;
        }
    }
    assert(maxAnsMask != -1);

    if(__builtin_popcount(maxAnsMask) == k)
    {
        for(int i = 0; i < n; i++)
            if((maxAnsMask >> i)&1)
                cout << i+1 << ' ';
    }
    else
    {
        for(int i = 0; i < n; i++)
            if(((maxAnsMask >> i)&1) != 1)
                cout << i+1 << ' ';

    }


    return 0;
}
