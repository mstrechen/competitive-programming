#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

const int maxN = 80;
const int max2N = 160;
const int max4N = 320;

bool field[max4N][max4N];

bool fieldCpy[8][max2N][max2N];

pair<int,int> dirXY[8] = {{0,1}, {1,1}, {1,0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1,1} };

void rec(vector<int> & a, int _i, int dir, int x, int y, int gDir)
{
    if(_i==a.size())
        return;
    for(int i = 0; i<a[_i]; i++)
    {
        x+=dirXY[dir].second;
        y+=dirXY[dir].first;
        fieldCpy[gDir][x][y] = 1;
    }

    rec(a, _i+1, (dir+1)%8, x,y, gDir);
    rec(a, _i+1, (dir+7)%8, x,y, gDir);
}

void makeOr(int x, int y, int dir)
{
    for(int i = 0; i<max2N; i++)
    for(int j = 0; j<max2N; j++)
        field[x+i][y+j]|=fieldCpy[dir][i][j];
}

void rec2(vector<int> & a, int _i, int dir, int x, int y)
{
    if(_i==a.size())
    {
        return;
    }

    for(int i = 0; i<a[_i]; i++)
    {
        x+=dirXY[dir].second;
        y+=dirXY[dir].first;
        field[x][y] = 1;
    }

    if(_i+1==a.size())
    {
       makeOr(x-maxN,y-maxN,dir);
    }
    rec2(a, _i+1, (dir+1)%8, x,y);
    rec2(a, _i+1, (dir+7)%8, x,y);
}



int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> firstPart((n-1)/2 + 1);
    vector<int> secondPart(n/2);

    for(auto & i : firstPart)
        cin >> i;
    for(auto & i : secondPart)
        cin >> i;


    for(int i = 0; i<8; i++)
    {
        rec(secondPart, 0, (i+1)%8, maxN, maxN, i);
        rec(secondPart, 0, (i+7)%8, maxN, maxN, i);
    }



    rec2(firstPart, 0, 0, max2N,max2N);

    int ans = 0;
    for(int i = 0; i<max4N; i++)
        for(int j = 0; j<max4N; j++)
            ans+=field[i][j];

    cout << ans;
    return 0;
}
