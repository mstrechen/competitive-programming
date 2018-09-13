#include<iostream>
#include<set>
#include<vector>

using namespace std;

int popcount(int a)
{
    int ans = 0;
    while(a)
    {
        ans += a&1;
        a>>=1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    int n1 = n;
    n = 100000;
    vector<int> up, down;
    int cur = 0;

    while(cur != -1)
    {
        cin >> cur;
        down.push_back(cur);
    }
    cur = 0;
    while(cur != -1)
    {
        cin >> cur;
        up.push_back(cur);
    }
    up.pop_back();
    down.pop_back();
    for(int mask = 15; mask>=0; mask--)
    if((q >= popcount(mask)) && (q%2 == popcount(mask)%2))
    {
        vector<int> a(n, !(mask&1));
        for(int i = 0; i<n; i++)
        {
            if(i%3 == 0)
                a[i] ^= (mask >> 1)&1;

            if(i%2 == 0)
                a[i] ^= (mask >> 2)&1;
            else
                a[i] ^= (mask >> 3)&1;
        }
        bool flag = 1;
        for(auto i : up)
        {
            if(i>n)
                continue;

            if(a[i-1])
                flag = 0;
        }
        for(auto i : down)
        {
            if(i>n)
                continue;

            if(!a[i-1])
                flag = 0;
        }
        if(flag)
        {
            for(int i = 0; i<n1; i++)
                cout << a[i];
            cout << '\n';
        }
    }



    return 0;
}
