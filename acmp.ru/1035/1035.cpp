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
    vector<int> a(n+1,0);
    vector<int> b(n+1,100500);



    for(int i = 0; i<n; i++)
        cin >> a[i];
    a[n] = 100500;

    sort(a.begin(),a.end());


    int x, y;

    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> x >> y;
        int delta = upper_bound(a.begin(),a.end(), x) - a.begin();
        b[delta] = min(b[delta], y);
    }

    int ans = 0;
    int mincost = *b.rbegin();
    for(int i = a.size()-2; i>=0; i--)
    {
        ans+=mincost;
        mincost = min(mincost, b[i]);
    }
    cout << ans;




	return 0;
}
