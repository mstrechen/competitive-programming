#include<iostream>
#include<vector>
#include<queue>
#include<cassert>

using namespace std;


int dist[50][50][50][50];


struct vctr
{
    int a,b,c,d;
    vctr(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){}
    int operator[](int i)
    {
        if(i==0)
            return a;
        if(i==1)
            return b;
        if(i==2)
            return c;
        if(i==3)
            return d;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> field(n);

    for(auto& i : field)
        cin >> i;

    int x0, y0, x1, y1;

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
        if(field[i][j]!='#')
        {
            if(field[i][j]=='.')
            {
                x0 = i;
                y0 = j;
                field[i][j] = 'c';
            }
            else
            if(field[i][j]=='X')
            {
                x1 = i;
                y1 = j;
                field[i][j] = 'c';
            }
        }
    vector<vctr> Q;
    Q.push_back({x0,y0,x1,y1});
    dist[x0][y0][x1][y1] = 1;

    int back = 0;

    while(Q.size()!=back)
    {
        x0 = Q[back][0];
        y0 = Q[back][1];
        x1 = Q[back][2];
        y1 = Q[back][3];

        back++;
        if(x0>0&&field[x0-1][y0]=='c' && !dist[x0-1][y0][x1+(x0==x1+1&&y0==y1)][y1])
        {
            Q.push_back({x0-1,y0,x1+(x0==x1+1&&y0==y1),y1});
            dist[x0-1][y0][x1+(x0==x1+1&&y0==y1)][y1] = dist[x0][y0][x1][y1]+1;
        }
        if(x0<n-1&&field[x0+1][y0]=='c' && !dist[x0+1][y0][x1-(x0==x1-1&&y0==y1)][y1])
        {
            Q.push_back({x0+1,y0,x1-(x0==x1-1&&y0==y1),y1});
            dist[x0+1][y0][x1-(x0==x1-1&&y0==y1)][y1] = dist[x0][y0][x1][y1]+1;
        }
        if(y0>0&&field[x0][y0-1]=='c'&&!dist[x0][y0-1][x1][y1+(y0==y1+1&&x0==x1)])
        {
            Q.push_back({x0,y0-1,x1,y1+(y0==y1+1&&x0==x1)});
           dist[x0][y0-1][x1][y1+(y0==y1+1&&x0==x1)] = dist[x0][y0][x1][y1]+1;
        }
        if(y0<m-1&&field[x0][y0+1]=='c'&&!dist[x0][y0+1][x1][y1-(y0==y1-1&&x0==x1)])
        {
            Q.push_back({x0,y0+1,x1,y1-(y0==y1-1&&x0==x1)});
           dist[x0][y0+1][x1][y1-(y0==y1-1&&x0==x1)] = dist[x0][y0][x1][y1]+1;
        }
    }

    int minCount = 1000*1000*1000;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            if(dist[i][j][0][0]!=0)
                minCount = min(minCount, dist[i][j][0][0]);

    if(minCount!=1000*1000*1000)
        cout << minCount-1;
    else
        cout << "Impossible";


    return 0;
}
