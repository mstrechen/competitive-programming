#include<iostream>
#include<vector>

using namespace std;

struct DSU
{
    vector<int> p;
    vector<int> N, M;

    DSU(int n) : p(n), N(n, 1), M(n, 0)
    {
        for(int i = 0; i<n; i++)
            p[i] = i;
    }

    int get(int i)
    {
        if(p[i] == i)
            return i;
        return p[i] = get(p[i]);
    }

    void unite(int a, int b)
    {
        a = get(a);
        b = get(b);

        if(a == b)
            M[a]++;
        else
        {
            M[a] += M[b]+1;
            N[a] += N[b];
            p[b] = a;
        }
    }
};

struct REC
{
    vector<vector<vector<char> > > dp;
    REC(): dp(2, vector<vector<char> >(151, vector<char>(151, 2) ) ) {};

    char get(int p, int m0, int m1)
    {
        if(dp[p][m0][m1] != 2)
        {
            return dp[p][m0][m1];
        }
        if(m0 + m1 == 1)
        {
            return 0;
        }
        if(m0 + m1 == 2)
        {
            return 1;
        }
        if(m0 + m1 == 3)
        {
            return p;
        }

        char ans = 0;

        if(m0>=2)
        {
            ans |= !get((p+1)%2, m0-1, m1);
        }
        if(m1>=2)
        {
            ans |= !get(p, m0+1, m1-2);
        }
        if(m1 >= 1 && m0 >= 1)
        {
            ans|= !get((p+1)%2, m0-1, m1);
        }
        if(p)
        {
            ans |= !get(0, m0, m1);
        }

        return dp[p][m0][m1] = ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    while(k--)
    {
        int n, m;
        cin >> n >> m;
        DSU D(n);

        for(int i = 0; i<m; i++)
        {
            int x,y;
            cin >> x >> y;
            D.unite(x-1,y-1);
        }

        int edgesLeft = 0;
        int mod0 = 0, mod1 = 0;

        for(int i = 0; i<n; i++)
        if(D.p[i] == i)
        {
            mod0 += (D.N[i]%2 == 0);
            mod1 += (D.N[i]%2 == 1);
            edgesLeft += D.N[i]*(D.N[i]-1)/2 - D.M[i];
        }

        REC R;
        if(R.get(edgesLeft%2, mod0, mod1))
        {
            cout << "Sergei\n";
        }
        else
        {
            cout << "Roman\n";
        }
    }

    return 0;
}
