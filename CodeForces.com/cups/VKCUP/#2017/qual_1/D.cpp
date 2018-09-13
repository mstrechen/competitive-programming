#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
    ifstream cin("D_2.txt");
    ofstream cout("D_2_ansM.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> cnt(1<<14, 0);

    vector<int> masks;
    masks.reserve(1<<14);

    for(int mask = (1<<14) - 1; mask>=0; mask--)
        if(__builtin_popcount(mask) == k)
            masks.push_back(mask);

    long long ans = 0;

    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        for(auto mask : masks)
        {
            ans+=cnt[x^mask];
        }
        cnt[x]++;
    }

    cout << ans;


    return 0;
}
