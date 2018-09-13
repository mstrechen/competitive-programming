#include<iostream>
#include<map>

using namespace std;

int main(){
    long long x, k;
    cin >> x >> k;

    long long min_k = 0;
    {
        long long x_cp = x;
        while(x_cp > 0)
            min_k += (x_cp & 1),
            x_cp >>= 1;
    }

    if(min_k > k ){
        cout << "No";
        return 0;
    } else {
        cout << "Yes\n";
        map<long long, long long> a;
        for(long long x_cp = x, i = 0; x_cp > 0; i++, x_cp /= 2)
        if(x_cp & 1){
            a[i] = 1;
        }

        for(pair<long long, long long> it = *a.rbegin(); ; it = *a.rbegin()){
            if(it.second + min_k <= k){
                min_k += it.second;
                a[it.first - 1] += it.second * 2;
                a.erase(it.first);
            } else{
                break;
            }

        }


        long long left_k = min_k;

        for(auto it = a.rbegin(); it != a.rend(); it++){
            if(left_k == it->second){
                for(long long i = it->second - 1; i > 0; i--){
                    cout << it->first << ' ';
                }
                long long diff = k - min_k;
                long long curval = it->first;
                while(diff != 0){
                    curval -= 1;
                    cout << curval << ' ';
                    diff--;
                }
                cout << curval;
            } else {
                for(long long i = it->second; i > 0; i--)
                    cout << it->first << ' ';
                left_k -= it->second;
            }
        }

    }




}
