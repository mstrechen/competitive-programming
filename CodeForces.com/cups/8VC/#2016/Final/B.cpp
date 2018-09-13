#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
    vector<int> t(1,-100500);
    vector<int> cost(1,0);

    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        t.push_back(x);
        int mincost;
        mincost = min(min(cost[i]+20,
                          cost[lower_bound(t.begin(), t.end(), x-89)-t.begin()-1] + 50),
                          cost[lower_bound(t.begin(), t.end(), x-1439)-t.begin()-1] + 120);

        cout << mincost - cost.back() << '\n';
        cost.push_back(mincost);
    }

	return 0;
}
