#include<iostream>
#include<vector>
#include<random>

using namespace std;
std::mt19937 gen(100500);
std::uniform_int_distribution<> dis(0, 1);
struct Possible
{
    int n, m;
    vector<vector<int> > & field;
    Possible(int n, int m, vector<vector<int> > & field) : n(n), m(m), field(field) {}
    vector<pair<int, int> > moves{  { 2, -1},
                                    {-1,  2},
                                    { 2,  1},
                                    {-2, -1},
                                    { 1, -2},
                                    { 1,  2},
                                    {-1, -2},
                                    {-2,  1}};

    bool is(int x, int y)
    {
        return 0 <= x &&
                x < n &&
               0 <= y &&
                y < m;
    }

    int getCount(int x, int y)
    {
        if(!is(x, y))
            return 100800;
        else
            if(field[x][y] != 0)
                return 100900;
        int cnt = 0;

        for(auto & i : moves)
            if(is(x + i.first, y + i.second) && (field[x + i.first][y + i.second] == 0 ) )
                cnt++;
        return cnt;
    }

    void findStep(int & x, int & y, int step)
    {
        for(int i = 0; i < (int)field.size(); i++)
            for(int j = 0; j < (int)field.size(); j++)
                if(field[i][j] == step)
                {
                    x = i, y = j;
                }
                else
                if(field[i][j] > step)
                    field[i][j] = 0;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > field(200, vector<int>(200, 0));
    Possible possible(n, m, field);

    int x = 0, y  = 0;
    int freePlaces = 0;

    {
        char tmp;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> tmp;
                if(tmp == 'K')
                    x = i, y = j;
                else
                if(tmp == 'X')
                    field[i][j] = -1;
                else
                    ++freePlaces;
            }
    }

    int cur = 1;

    do
    {
        field[x][y] = cur++;
        int minI = -1;
        int minRes = 1000;
        int found = 0;
        for(int i = 0; i < 8; i++)
        {
            int tmp = possible.getCount(x + possible.moves[i].first, y + possible.moves[i].second);
            if(tmp < minRes)
            {
                minI = i, minRes = tmp;
                found = 1;
            }
            else
                if(tmp == minRes )
                {
                    found++;
                    std::uniform_int_distribution<> get(0, found-1);
                    if(get(gen) == 0)
                        minI = i, minRes = tmp;
                }
        }
        if(minI == -1)
        {
            std::uniform_int_distribution<> getStep(1, cur);
            possible.findStep(x, y, cur);
            continue;
        }
        x += possible.moves[minI].first;
        y += possible.moves[minI].second;
    }
    while(cur != freePlaces + 2);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << max(field[i][j], 0) << ' ';
        cout << '\n';
    }

    return 0;
}
