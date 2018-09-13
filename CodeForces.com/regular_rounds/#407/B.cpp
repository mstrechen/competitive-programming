#include<iostream>
#include<set>
#include<cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long b0, q, l, m;
    set<long long> A;

    cin >> b0 >> q >> l >> m;

    for(int i = 0; i<m; i++)
    {
        int x;
        cin >> x;
        A.insert(x);
    }

    if(b0 == 0)
    {
        if(A.count(0))
            cout << 0;
        else
            cout << "inf";
    }
    else
    if(q == 0)
    {
        if(abs(b0) <= l)
        {
            if(A.count(0))
                cout << 1-A.count(b0);
            else
                cout << "inf";
        }
        else
            cout << 0;
    }
    else
    if(q == 1)
    {
        if(A.count(b0) || abs(b0) > l)
        {
            cout << 0;
        }
        else
            cout << "inf";
    }
    else
    if(q == -1)
    {
        if(abs(b0) > l || (A.count(b0) && A.count(-b0)))
            cout << 0;
        else
            cout << "inf";
    }
    else
    {
        int cnt = 0;
        while(abs(b0) <= l)
        {
            cnt += 1 - A.count(b0);
            b0*=q;
        }
        cout << cnt;
    }

    return 0;
}
