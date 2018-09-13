#include<iostream>

using namespace std;

const int MAXN = 1005;

int dist[MAXN][MAXN];

pair<int,int> Q[MAXN*MAXN];
int H,T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        if(x)
            for(int j = 0; j<n; j++)
                dist[i][j] = -1;
    }
    if(dist[n-1][0])
    {
        cout << -1;
        return 0;
    }

    if(dist[0][0] == 0)
    {
        Q[T++]  = {0,0};
        dist[0][0] = 1;
    }


    while(H!=T)
    {
        int curpos = Q[H].first,
            curLen = Q[H].second;

        int curDist = dist[curpos][curLen];
        H++;

        for(int delta = -1; delta<=1; delta++)
        {
            int alterLen = curLen+delta;
            if(alterLen>=0)
            {
                if(curpos>=alterLen && dist[curpos-alterLen][alterLen] == 0)
                {
                    dist[curpos-alterLen][alterLen] = curDist + 1;
                    Q[T++] = {curpos-alterLen, alterLen};
                }
                if(curpos+alterLen < n && dist[curpos+alterLen][alterLen] == 0)
                {
                    dist[curpos+alterLen][alterLen] = curDist + 1;
                    Q[T++] = {curpos+alterLen, alterLen};
                }
                if(curpos+alterLen == n-1)
                {
                    cout << dist[curpos+alterLen][alterLen]-1;
                    return 0;
                }
            }
        }

    }
    cout << -1;


    return 0;
}
