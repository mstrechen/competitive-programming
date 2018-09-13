#include<iostream>
#include<vector>
#include<bitset>

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

struct BitpackedArray
{
    bitset<150*150*150*150> a;
    BitpackedArray(){ a.reset();}

    bool operator () (int i1, int i2, int i3, int i4)
    {
        return a[((i1*150 + i2)*150 + i3)*150+i4];
    }

    void set(int i1, int i2, int i3, int i4, bool val)
    {
        a[((i1*150 + i2)*150 + i3)*150+i4] = val;
    }
};

struct RecursionSolver
{
    BitpackedArray used{}, mem{};

    bool getAns(int v00, int v01, int v10, int v11)
    {
        if(v00+v01+v10+v11 == 1)
            return 0;
        if(v00+v01+v10+v11 == 2)
            return 1;
        if(v00+v01+v10+v11 == 3)
            return (v01+v11)%2;

        if(used(v00, v01, v10, v11))
            return mem(v00, v01, v10, v11);

        used.set(v00, v01, v10, v11, 1);

        bool ans = 1;

        if(v00>1)
        {
            ans &= getAns(v00-2, v01+1, v10, v11);
        }
        if(v01>1)
        {
            ans &= getAns(v00, v01-2+1, v10, v11);
        }
        if(v10>1)
        {
            ans &= getAns(v00+1, v01, v10-2, v11);
        }
        if(v11>1)
        {
            ans &= getAns(v00+1, v01, v10, v11-2);
        }
        if(v00 && v01)
        {
            ans &= getAns(v00-1+1, v01-1, v10, v11);
        }
        if(v00 && v10)
        {
            ans &= getAns(v00-1, v01, v10-1, v11+1);
        }
        if(v00 && v11)
        {
            ans &= getAns(v00-1, v01, v10+1, v11-1);
        }
        if(v01 && v10)
        {
            ans &= getAns(v00, v01-1, v10-1+1, v11);
        }
        if(v01 && v11)
        {
            ans &= getAns(v00, v01-1, v10, v11-1+1);
        }
        if(v10 && v11)
        {
            ans &= getAns(v00, v01+1, v10-1, v11-1);
        }
        if(v01)
        {
            ans &= getAns(v00+1, v01-1, v10, v11);
        }
        if(v11)
        {
            ans &= getAns(v00, v01, v10+1, v11-1);
        }


        ans^=1;
        mem.set(v00, v01, v10, v11, ans);
        return ans;
    }

};
RecursionSolver RC;

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

        int v00 = 0, v01 = 0, v10 = 0, v11 = 0;

        for(int i = 0; i<n; i++)
        if(D.p[i] == i)
        {
            if(D.N[i]%2)
            {
                if((D.N[i]*(D.N[i]-1)/2 - D.M[i])%2)
                    v11++;
                else
                    v10++;
            }
            else
            {
                if((D.N[i]*(D.N[i]-1)/2 - D.M[i])%2)
                    v01++;
                else
                    v00++;
            }
        }

        RC.used.a.reset();
        if(RC.getAns(v00, v01, v10, v11))
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
