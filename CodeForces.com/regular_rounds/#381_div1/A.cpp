#include<iostream>
#include<set>
#include<vector>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    int minlen = 100500;

    int l,r;
    for(int i = 0; i<m; i++)
    {
        cin >> l >> r;
        minlen = min(minlen, r-l+1);
    }
    cout << minlen << '\n';
    for(int i = 0, j =0; i<n; i++)
    {
        cout << (j++) << ' ';
        j%=minlen;
    }

    return 0;
}
