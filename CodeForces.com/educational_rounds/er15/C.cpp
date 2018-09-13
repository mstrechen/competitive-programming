#include<iostream>
#include<functional>
#include<set>

using namespace std;

set<int> A;
set<int, greater<int>> B;

int a[100500];

int main()
{
    ios::sync_with_stdio(false);
    int n,m, tmp;
    int res = 0;
    cin >> n >> m;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i<m; i++)
    {
        cin >> tmp;
        A.insert(tmp);
        B.insert(tmp);
    }
    for(int i = 0; i<n; i++)
    {
        tmp = 2*1e9+5;
        if(A.lower_bound(a[i])!=A.end())
        {
            tmp = *A.lower_bound((a[i])) - a[i];
        }
        if(B.lower_bound(a[i])!=B.end())
        {
            tmp = min(a[i] - *B.lower_bound((a[i])), tmp);
        }
        res = max(res, tmp);
    }
    cout << res;
    return 0;
}
