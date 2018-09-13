#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 4 ;


    vector<int> f(n), g(n), h(n);

    for(f[0] = 0; f[0]<4; f[0]++)
    for(f[1] = 0; f[1]<4; f[1]++)
    for(f[2] = 0; f[2]<4; f[2]++)
    for(f[3] = 0; f[3]<4; f[3]++)
    {
        for(g[0] = 0; g[0]<4; g[0]++)
    for(g[1] = 0; g[1]<4; g[1]++)
    for(g[2] = 0; g[2]<4; g[2]++)
    for(g[3] = 0; g[3]<4; g[3]++)
    for(h[0] = 0; h[0]<4; h[0]++)
    for(h[1] = 0; h[1]<4; h[1]++)
    for(h[2] = 0; h[2]<4; h[2]++)
    for(h[3] = 0; h[3]<4; h[3]++)
    {
        bool res = 1;
        for(int i = 0; i<4; i++)
            res &= (g[h[i]] == i) && (h[g[i]] == f[i]);

        if(res)
        {
            for(auto i : f)
                cout << i << ' ';
            cout << '#'<< endl;
            for(auto i : g)
                cout << i << ' ';
            cout << ':' << endl;
            for(auto i : h)
                cout << i << ' ';
            cout << endl;
        }

    } for(auto i : f)
                cout << i << ' ';
                cout << "CHECK" << endl;
    }


    return 0;
}
