#include<iostream>
#include<vector>




using namespace std;

const unsigned int SZ = 30;
const unsigned int MASK = (1 << 30) - 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    for(auto & i : a)
        cin >> i;
    for(auto & i : a)
        for(auto & j : i)
            j -= '0';

    int MASK_LAST = (1 << ((n - 1) % SZ + 1)) - 1;

    vector<vector<unsigned int> > msk(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            if(j % SZ == 0){
                msk[i].push_back((unsigned)a[i][j]);
            } else {
                msk[i].back() += int(a[i][j]) << (j % SZ);
            }
    }
    long long ans = 0;
    for(int _i = 0; _i < n; _i++){
        auto & v1 = msk[_i];
        for(int _j = _i+1; _j < n; _j++){
            auto & v2 = msk[_j];

            int16_t v00 = 0, v01 = 0, v10 = 0, v11 = 0;
            for(int i = 0; i < (int)v1.size() - 1; i++){
                v11 += __builtin_popcount(v1[i] & v2[i]);
                v00 += __builtin_popcount((~(v1[i] | v2[i])) & MASK);
                v01 += __builtin_popcount((~v1[i]) & v2[i]) ;
                v10 += __builtin_popcount((~v2[i]) & v1[i]) ;
            }
            int i = (int)v1.size() - 1;
            v11 += __builtin_popcount(v1[i] & v2[i]);
            v00 += __builtin_popcount((~(v1[i] | v2[i])) & MASK_LAST);
            v01 += __builtin_popcount((~v1[i]) & MASK_LAST & v2[i]) ;
            v10 += __builtin_popcount((~v2[i]) & MASK_LAST & v1[i]) ;
            ans += (v11 * int(v11 - 1)) / 2;
            ans += (v00 * int(v00 - 1)) / 2;
            ans += v01 * int(v10);
        }

    }

    cout << ans;

    return 0;
}
