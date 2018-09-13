#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        vector<pair<int, int> > a(n);
        for(int i = 0; i<n; i++)
        {
            cin >>  a[i].first;
            a[i].second = i;
        }
        for(int i = 1; i<n; i++)
            a[i] = max(a[i],a[i-1]);

        bool pairty = 0;
        int i = n-1;
        while(i!=-1)
        {
            i = a[i].second - 1;
            pairty^=1;
        }
        cout << (pairty?"BOB\n":"ANDY\n");

    }

    return 0;
}
