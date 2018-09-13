#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Tree
{
    int n;
    vector<vector<int> > e;
    vector<int> color;

    Tree(int n) : n(n), e(n), color(n,0){}

    void add(int a, int b)
    {
        --a, --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    void dfs(int v, int prevColor, int curColor)
    {
        color[v] = curColor;
        int nextColor = 0;

        for(auto i : e[v])
        if(color[i] == 0)
        {
            do{nextColor++;}while(nextColor==curColor || nextColor==prevColor);
            dfs(i, curColor, nextColor);
        }
    }

    void make()
    {
        dfs(0, -1, 1);
    }

};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Tree T(n);

    for(int i = 1; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        T.add(x,y);
    }

    T.make();

    cout << accumulate(T.color.begin(), T.color.end(), 0, [](int a, int b){return max(a,b);}) << '\n';
    for(auto i : T.color)
        cout << i << ' ';

    return 0;
}
