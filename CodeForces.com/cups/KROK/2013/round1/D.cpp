#include<iostream>
#include<vector>

using namespace std;


struct DSU
{
    vector<int> p;

    DSU(int n)
    {
        p.assign(n,0);
        for(int i = 1; i<n; i++)
            p[i] = i;
    }

    int get(int i)
    {
        return ((p[i]==i)?i:p[i] = get(p[i]));
    }

    void unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if(x!=y)
            p[x] = y;
    }

};

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);



    return 0;
}
