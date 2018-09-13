#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> a(n);

    for(auto & i : a)
    {
        cin >> i;
    }

    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    for(auto & i : a)
    {
        if(i == mx || i == mn)
            n--;
    }
    cout << n;

    return 0;
}
