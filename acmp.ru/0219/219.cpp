#include<iostream>
#include<vector>

using namespace std;

struct Network{
    int n, m;

    int size;
    int be, en;
    vector<vector<int> > c;
    vector<int> colors;
    int currentColor;

    Network(int n, int m) : size(n + m + 2), n(n), m(m),
                     be(n + m),
                     en(n + m + 1),
                     c(size, vector<int>(size, 0)),
                     colors(size, 0),
                     currentColor(1){}

    bool init(const vector<int> & R, const vector<int> & C,
              const vector<vector<char> > & used){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(!used[i][j]){
                    c[i][j + n] = 1000*1000*1000;
                }
            }

        for(int i = 0; i < n; i++){
            c[be][i] = R[i];
        }
        for(int i = 0; i < m; i++){
            c[i + n][en] = C[i];
        }
    }

    int minValue;
    bool findAnyPath(int v)
    {
        if(v == en)
            return 1;
        colors[v] = currentColor;

        for(int i = 0; i < size; i++)
            if(c[v][i] >= minValue && colors[i] != currentColor){
                c[v][i] -= minValue;
                c[i][v] += minValue;

                if(findAnyPath(i))
                    return 1;

                c[v][i] += minValue;
                c[i][v] -= minValue;
            }
        return 0;
    }

    int getMaxFlow()
    {
        minValue = 1000*1000*1000;
        while(minValue)
        {
            while(findAnyPath(be)){
                    currentColor++;
            }

            minValue/=2;
        }

        int ans = 0;

        for(int i = 0; i < size; i++)
            ans += c[i][be];
        return ans;
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> R(n), C(m);
    vector<vector<char> > used(n, vector<char>(m, 0));

    for(int i = 0; i < n; i++)
        cin >> R[i];
    for(int i = 0; i < m; i++)
        cin >> C[i];

    int beginAns = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            int tmp;
            cin >> tmp;
            if(tmp != -1)
            {
                used[i][j] = 1;
                R[i] -= tmp;
                C[j] -= tmp;
                beginAns += tmp;
            }
        }

    bool brokenField = 0;
    for(int i = 0; i < n && !brokenField; i++)
        if(R[i] < 0)
            brokenField = 1;
    for(int i = 0; i < m && !brokenField; i++)
        if(C[i] < 0)
            brokenField = 1;

    if(brokenField)
        cout << -1;
    else{
        Network N(n, m);
        N.init(R, C, used);
        cout << N.getMaxFlow() + beginAns;
    }

    return 0;
}
