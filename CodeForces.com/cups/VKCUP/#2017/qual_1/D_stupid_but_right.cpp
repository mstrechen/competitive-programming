#include<iostream>
#include<fstream>
#include<vector>


using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i<n; i++)
        cin >> a[i];

    long long ans = 0;

    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            ans+=(__builtin_popcount(a[i]^a[j]) == k);

    cout << ans;


    return 0;
}
