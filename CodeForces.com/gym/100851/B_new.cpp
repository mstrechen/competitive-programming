#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

using ULL = unsigned __int128;


vector<ULL> powers5{1};

ULL get_binary_by_mask(ULL n){
    ULL one = 1;
    ULL res = 0;
    for(ULL i = 0; i < 64; ++i){
        res += (one << i)*powers5[i]*((n >> i) & 1);
    }

    return res;
}

bool is_suffix(ULL s, ULL suf){
    while(suf > 0){
        if((suf ^ s)&1)
            return 0;
        suf >>= 1;
        s >>= 1;
    }
    return 1;
}

string bin_int_to_string(ULL src){
    if(src == 0)
        return "0";
    string res;
    while(src > 0)
        res.push_back(src%2 + '0'),
        src/=2;
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("binary.in");
    ofstream cout("binary.out");
    int n;



    for(int i = 1; i < 128; i++)
        powers5.push_back(powers5.back()*5);
    cin >> n;


    set<ULL> nums = {0, 1};



    ULL cur_digit = 2;
    while(nums.size() - 1 < n && cur_digit){
        for(auto i : nums){

            if(i >= cur_digit)
                break;
            if(is_suffix(get_binary_by_mask(i + cur_digit), i + cur_digit))
                        nums.insert(i + cur_digit);
        }
        cur_digit *= 2;

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

