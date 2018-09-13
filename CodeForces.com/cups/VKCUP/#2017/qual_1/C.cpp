#include<iostream>
#include<vector>

using namespace std;

struct Field
{
    vector<pair<pair<int,int>, char> > turns{{{1, 0}, 'D'}, {{0, -1}, 'L'}, {{0, 1}, 'R'}, {{-1, 0}, 'U'}};

    int n,m;
    int len;

    vector<string> field;
    vector<vector<int>> used{};


    Field(int n, int m, int k) : n(n), m(m), len(k),  field(n) {}

    char inversed(char c)
    {
        if(c == 'U' || c == 'D')
            return 'U'^'D'^c;
        return 'L'^'R'^c;
    }


    string res{};
    bool dfs(int x, int y, int dist)
    {
        if(x < 0 || n <= x || y < 0 || m <= y)
            return 0;
        if(field[x][y] == '*')
            return 0;

        if(used[x][y] == -1)
            used[x][y] = dist;
        if(used[x][y] + dist == len)
            return 1;

        for(auto & i : turns)
        {
            res.push_back(i.second);
            if(dfs(x+i.first.first, y+i.first.second, dist+1))
                return 1;
            res.pop_back();
        }
        return 0;
    }

    string getAns()
    {
        if(len%2)
            return "IMPOSSIBLE";
        res.clear();
        used.assign(n, vector<int>(m, -1));

        int xBe = -1, yBe = -1;

        for(int i = 0; i<n; i++)
        {
            auto j = field[i].find('X', 0);
            if(j != string::npos)
                xBe = i, yBe = j;
        }

        if(!dfs(xBe, yBe, 0))
            return "IMPOSSIBLE";

        int left = len - res.size();

        for(int i = left-1; i>=0; i--)
            res.push_back(inversed(res[i]));

        return res;
    }

};




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;

    cin >> n >> m >> k;

    Field F(n, m, k);

    for(int i = 0; i<n; i++)
        cin >> F.field[i];

    cout << F.getAns();

    return 0;
}
