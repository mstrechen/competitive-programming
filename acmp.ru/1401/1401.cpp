#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto & i : a)
        cin >> i;

    int max_value_to_work_with = 1000*1000*1000/k;
	long long ans = 0;
	sort(a.begin(), a.end());
	for(auto it = a.begin(); it != a.end(); it++){
		auto last_iter = 
			*it <= max_value_to_work_with ? 
					upper_bound(a.begin(), a.end(), *it * k) : a.end();
		long long short_ans = last_iter - it - 1;
		ans += (short_ans*(short_ans - 1)/2)*6;
	}
	cout << ans;


    return 0;
}
