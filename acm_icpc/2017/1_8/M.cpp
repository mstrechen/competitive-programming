#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> mp;
    vector<int> a(n);
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        a[i] = x;
    }

    sort(a.begin(), a.end());

    int prev = -1;


    for(auto i : a)
    if(prev!=i)
    {
        prev  = i;
        int cnt = mp[i];
        mp[(i/3)*4] -= cnt;
        while(cnt--)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
