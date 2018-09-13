#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<set>
#include<bitset>

using namespace std;

using UL = unsigned int;

const int LEN = 64;
using UINT = bitset<LEN>;

UINT operator * (const UINT & a, bool b){
    if(b)
        return a;
    return 0;
}


UINT operator += (UINT & a, const UINT & b){
    int carry = 0;
    for(int  i = 0; i < LEN; i++){
        carry += a[i] + b[i];
        a.set(i, carry&1);
        carry >>= 1;
    }
    return a;
}
UINT operator * (UINT a, int b){
    UINT res;
    while(b){
        if(b&1)
            res += a;
        a <<= 1;
        b >>= 1;
    }
    return res;
}



vector<UINT> powers5 = {UINT(1)};

UINT get_binary_by_mask(UINT n){
    UINT res = 0;
    for(int i = 0; i < LEN; ++i){
        res += (powers5[i] << i)*bool(n[i]);
    }

    return res;
}

bool is_suffix(UINT s, UINT suf){
    auto tmp = suf^s;
    int len = LEN - 1;
    while(len && !suf[len])
        len--;
    ++len;
    while(len--)
        if(suf[len]^s[len])
            return 0;
    return 1;
}

string bin_int_to_string(UINT & to_write){
    string res = to_write.to_string();
    int i;
    for(i = 0; i < LEN && res[i] == '0'; ++i);
    return string(res.begin() + i, res.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream cin("binary.in");
    //ofstream cout("binary.out");
    int n;


    for(int i = 1; i < LEN; i++){
        powers5.push_back(powers5.back()*5);
    }
    cin >> n;


    vector<UINT> nums = {0, 1};



    UINT cur_digit = 2;
    while(nums.size() - 1 < n){
        int cur_size = nums.size();
        for(int j = 0; j < cur_size; j++){
            auto i = nums[j];
            auto tmp = i;
            tmp += cur_digit;
            if(is_suffix(get_binary_by_mask(tmp), tmp))
                        nums.push_back(tmp);
        }
        cur_digit <<= 1;

    }


    int j = 0;
    for(auto i : nums){
        if(j == n){
            cout << bin_int_to_string(i);
            return 0;
        }
        ++j;
    }

    return 0;
}

