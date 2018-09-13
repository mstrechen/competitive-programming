#include<iostream>
#include<set>
using namespace std;
long long x,y,n,cg,minn;
set<long long> ans;
long long gcd(long long a, long long b)
{
    if (a>b)
        swap(a,b);
    if (a==0) return b;
    return gcd(a,b%a);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> x >> y;
    minn=y;
    cg=x-y;
    for (int i=1;i<n;i++)
    {
        cin >> x >> y;
        minn=max(y,minn);
        cg=gcd(cg,x-y);
    }
    minn++;
    for (long long i=1;i*i<=cg;i++)
    {
        if (cg%i==0)
        {
            if (i>=minn)
            {
               ans.insert(i);
            }
            if (cg/i>=minn)
            {
                ans.insert(cg/i);
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto i:ans)
    {
        cout << i << " ";
    }
    return 0;
}
