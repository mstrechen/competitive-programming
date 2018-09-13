#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, ans = 0, ansBit = 0;
    cin >> n;

    vector<int> to(n,0), used(n,0);

    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> to[i];
        to[i]--;
    }

    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        ansBit^=x;
    }

    for(int i = 0; i<n; i++)
        if(!used[i])
        {
            int j = i;
            while(!used[j])
            {
                used[j] = 1;
                j = to[j];
            }
            if(j==i)
                ans++;
        }

    if(ans==1)
        ans = 0;

    cout << ans + 1 - ansBit;

	return 0;
}
