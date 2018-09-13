#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n,q;
    cin >> n >> q;
	vector<int> servers(n,0);

	for(int i = 0; i<q; i++)
    {
        int t, needServers, delay;
        cin >> t >> needServers >> delay;

        int countOfFree = 0;
        for(int i = 0; i<n; i++)
            countOfFree+=servers[i]<=t;

        if(countOfFree<needServers)
        {
            cout << -1 << '\n';
        }
        else
        {
            countOfFree = 0;
            for(int i = 0; i<n&&needServers; i++)
            if(servers[i]<=t)
            {
                servers[i] = t+delay;
                needServers--;
                countOfFree+=i+1;
            }
            cout << countOfFree << '\n';
        }
    }

	return 0;
}
