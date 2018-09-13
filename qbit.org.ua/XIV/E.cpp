#include<iostream>
#include<vector>

using namespace std;

struct SparceTable
{
    vector<vector<int> > MI{}, MA{};


    SparceTable(int n, int m, vector<vector<int>> & f)
    {
        MI.assign(1024, vector<int>(1024, 100500));
        MA.assign(1024, vector<int>(1024, -100500));
        for(int i = 0; i<n; i++)
            for(int j = 0; i<m; j++)
                MA[i][j] = MI[i][j] = f[i][j];


    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, d;
    cin >> n >> m >> d;

    return 0;
}
