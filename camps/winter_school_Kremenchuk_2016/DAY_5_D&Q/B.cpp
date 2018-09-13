#include<iostream>
#include<vector>
#include<cassert>
#include<set>

using namespace std;

const int oo = 2*1000*1000*1000;

struct query
{
    int x1, y1, x2, y2;
    query(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : x1(x1), y1(y1), x2(x2), y2(y2){}
};

istream & operator >> (istream & inStream, query & toRead)
{
    inStream >> toRead.x1 >> toRead.y1 >> toRead.x2 >> toRead.y2;
    if(toRead.y1>toRead.y2)
    {
        swap(toRead.x1,toRead.x2);
        swap(toRead.y1,toRead.y2);
    }
    return inStream;
}

struct DistInQueue
{
    int x, y, dist;
    DistInQueue(int x = 0, int y = 0, int dist = +oo) : x(x), y(y), dist(dist){}
};

bool operator < (const DistInQueue & a, const DistInQueue & b)
{
    if(a.dist!=b.dist)
        return a.dist < b.dist;
    else
    {
        if(a.x!=b.x)
           return a.x<b.x;
        else
            return a.y<b.y;
    }

}

struct Dijkstra
{
    vector<vector<int> > field;
    vector<vector<int> > dist;
    int n;
    Dijkstra(vector<vector<int> > & fieldSource) : n(fieldSource.size())
    {
        field.swap(fieldSource);
        dist.assign(field.size(), vector<int>(field[0].size(), +oo));
    }

    int operator()(int x, int y) const
    {
        return dist[x][y];
    }

    int at(int x, int y) const
    {
        return field[x][y];
    }

    void makeDijikstra(int _x, int _y, int l, int r)
    {
        for(int i = 0; i<n; i++)
            for(int j = l; j<=r; j++)
                dist[i][j] = +oo;

        set<DistInQueue> Q;

        dist[_x][_y] = field[_x][_y];

        Q.insert(DistInQueue(_x,_y,field[_x][_y]));

        while(!Q.empty())
        {
            DistInQueue tmp = *Q.begin();
            int x = tmp.x;
            int y = tmp.y;
            int curDist = tmp.dist;

            Q.erase(Q.begin());

            if(x>0 && dist[x-1][y]>dist[x][y]+field[x-1][y])
            {
                Q.erase(DistInQueue(x-1,y,dist[x-1][y]));
                dist[x-1][y] = dist[x][y]+field[x-1][y];
                Q.insert(DistInQueue(x-1,y,dist[x-1][y]));
            }
            if(x<n-1 && dist[x+1][y]>dist[x][y]+field[x+1][y])
            {
                Q.erase(DistInQueue(x+1,y,dist[x+1][y]));
                dist[x+1][y] = dist[x][y]+field[x+1][y];
                Q.insert(DistInQueue(x+1,y,dist[x+1][y]));
            }
            if(y>l &&  dist[x][y-1]>dist[x][y]+field[x][y-1])
            {
                Q.erase(DistInQueue(x,y-1,dist[x][y-1]));
                dist[x][y-1] = dist[x][y]+field[x][y-1];
                Q.insert(DistInQueue(x,y-1,dist[x][y-1]));
            }
            if(y<r &&  dist[x][y+1]>dist[x][y]+field[x][y+1])
            {
                Q.erase(DistInQueue(x,y+1,dist[x][y+1]));
                dist[x][y+1] = dist[x][y]+field[x][y+1];
                Q.insert(DistInQueue(x,y+1,dist[x][y+1]));
            }

        }

    }
};


void solve(int l, int r, vector<int> & idsToSolve, vector<query> & Q, Dijkstra & D, vector<int> & answers)
{
    if(idsToSolve.size()==0 || l>r)
        return;
    int mid = (l+r)/2;
    for(int _i = 0; _i<D.n; _i++)
    {
        D.makeDijikstra(_i, mid, l, r);
        for(auto i : idsToSolve)
        {
            answers[i] = min(answers[i], D(Q[i].x1, Q[i].y1)+D(Q[i].x2, Q[i].y2) - D.at(_i,mid));
        }
    }
    vector<int> forNext;
    for(auto & i : idsToSolve)
    {
        if(Q[i].y2<mid)
            forNext.push_back(i);
    }
    solve(l, mid-1, forNext, Q, D, answers);
    forNext.clear();

    for(auto & i : idsToSolve)
    {
        if(Q[i].y1>mid)
            forNext.push_back(i);
    }
    solve(mid+1, r, forNext, Q, D, answers);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;

    cin >> n >> m;
    vector<vector<int> > field(n, vector<int>(m,0));

    for(auto & i : field)
        for(auto & j : i)
            cin >> j;

    int qN;
    cin >> qN;
    vector<query> Q(qN);

    for(auto & i : Q)
    {
        cin >> i;
    }

    vector<int> IDs(qN);
    vector<int> answers(qN, +oo);

    Dijkstra D(field);

    for(int i = 0; i<(int)IDs.size(); i++)
        IDs[i] = i;

    solve(0, m-1,  IDs, Q, D, answers);

    for(auto i : answers)
        cout << i << '\n';

    return 0;
}
