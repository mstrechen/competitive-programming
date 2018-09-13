#include<iostream>
#include<vector>

using namespace std;


struct st
{
    int x, y, z;
    st(int x = 0, int y = 0, int z = 0):x(x),y(y),z(z){};

    int ok(st a)
    {
        return (((a.x==x)+(a.y==y)+(a.z==z))<2);
    }
    int _xor(st a)
    {
        return (a.x^x^a.y^y^a.z^z);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<st> removed;

    int n,m;
    cin >> n >> m;

    vector<int> curr(n, 0);
    st tmp;

    for(int i = 0; i<m; i++)
    {
        curr.assign(n,0);
        cin >> tmp.x >> tmp.y >> tmp.z;
        for(auto i : removed)
        {
            if(i.ok(tmp))
            {
                curr[i._xor(tmp) - 1] = 1;
            }
        }
        int x = tmp.x;
        int y = tmp.y;
        int z = tmp.z;
        if(x==0)
        {
            for(int i = 0; i<n; i++)
            if(curr[i]==0)
            {
                removed.push_back(st(i+1,y,z));
            }
        }
        if(y==0)
        {
            for(int i = 0; i<n; i++)
            if(curr[i]==0)
            {
                removed.push_back(st(x,i+1,z));
            }
        }
        if(z==0)
        {
            for(int i = 0; i<n; i++)
            if(curr[i]==0)
            {
                removed.push_back(st(x,y,i+1));
            }
        }

    }

    cout << n*n*n - removed.size();

    return 0;
}
