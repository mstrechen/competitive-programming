#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    double x;

    cin >> n >> m;
    vector<double> a(n,0);

    for(int i = 0; i<n; i++)
        cin >> a[i];

    for(int i = 0; i<m; i++)
    {
        cin >> x;
        cout << (binary_search(a.begin(),a.end(), x)?"YES " : "NO ");
    }

    return 0;
}
