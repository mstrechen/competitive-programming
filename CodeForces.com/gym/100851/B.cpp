#include<iostream>
#include<fstream>
#include<algorithm>
#include<set>

using namespace std;

bool is_suffix(const string & s, const string & suf){
    if(s.size() < suf.size())
        return 0;
    return equal(s.end() - suf.size(), s.end(), suf.begin());
}

string int_to_string(long long src){
    if(src == 0)
        return "0";
    string res;
    while(src > 0)
        res.push_back(src%10 + '0'),
        src/=10;
    reverse(res.begin(), res.end());
    return res;
}

long long bin_to_dec(unsigned m){
    long long res = 0;
    for(long long i = 1, j = 1; i <= m; i*=2, j*=10){
        if(m & i)
            res += j;
    }
    return res;
}

string bin_int_to_string(long long src){
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
    //ifstream cin("binary.in");
    //ofstream cout("binary.out");
    int n;
    cin >> n;

    set<long long> nums = {0, 1};

    long long cur_digit = 10;
    while(nums.size() - 1 < n){
        for(auto i : nums){

            if(i >= cur_digit)
                break;
            if(is_suffix(bin_int_to_string(i + cur_digit),
                             int_to_string(i + cur_digit)))
                                nums.insert(i + cur_digit);
            cout << bin_int_to_string(i + cur_digit) << endl;
            cout << int_to_string(i + cur_digit) << endl;
        }
        cur_digit *= 10;

    }
    int j = 0;
    for(auto i : nums){
        if(j == n){
            cout << i;
            return 0;
        }
        ++j;
    }

    return 0;
}
