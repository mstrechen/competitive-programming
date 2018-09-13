#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

string tern(int n)
{
    string s;
    s += n/9 + '1';
    s += (n/3)%3 + '1';
    s += (n)%3 + '1';
    return s;
}

struct Network
{
    int from{27+27};
    int to{27+28};
    int n{27+29};
    vector<vector<int> > c{vector<vector<int> >(n, vector<int>(n, 0))};
    vector<vector<int> > f{vector<vector<int> >(n, vector<int>(n, 0))};
    Network()
    {
        for(int i = 0; i<27; i++)
            c[from][i] = 1;
        for(int i = 0; i<27; i++)
            c[i+27][to] = 1;
    }

    void addEdge(int x, int y)
    {
        c[x][y+27] = 1;
    }

    vector<char> used{};
    bool dfs(int v)
    {
        cout << v << endl;
        used[v] = 1;
        if(v == to)
            return 1;
        for(int i = 0; i<n; i++)
            if(c[v][i] - f[v][i] > 0)
            {
                if(dfs(i))
                {
                    c[v][i]--;
                    f[v][i]++;
                    return 1;
                }
            }
        return 0;
    }

    void findSol(ostream & out)
    {
        used.assign(n, 0);
        while(dfs(from))
        {
            used.assign(n, 0);
        }
        for(int i = 0; i<n-2; i++)
        {
            for(int j = 0; j<n-2; j++)
                if(f[i][j])
                    out << tern(i) << ' ' << tern(j-27) << endl;
        }
    }

};

int tern(string s)
{
    return (s[0]-'1')*9 + (s[1]-'1')*3 + (s[2]-'1');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("inp.txt");

    Network N;
    string s1, s2;
    cin >> s1;
    while(s1 != "$")
    {
        cin >> s2;
        N.addEdge(tern(s1), tern(s2));
        cin >> s1;
        cout << s1 << ' ' << s2 << endl;
    }

    ofstream cout("out.txt");
    N.findSol(cout);

    return 0;
}
