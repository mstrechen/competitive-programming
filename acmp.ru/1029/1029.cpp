#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int ans = n*n*n;


	set<vector<int>> A;

	vector<int> tmp(3,0);

	for(;m; m--)
    {
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        int _x = (tmp[1]==0)+2*(tmp[2]==0);
        for(tmp[_x] = 1; tmp[_x]<=n; tmp[_x]++)
        {
            ans--;
            ans+=A.count(tmp);
            A.insert(tmp);
        }
    }
    cout << ans;

	return 0;
}
