#include<iostream>
#include<fstream>

using namespace std;


const long long INF = 1000000000000000000;

long long dyn[200][200][200];

long long p[200][200];


int a[200];


long long get(int PLACE, int m, int k, int prevColor)
{
    if(k<0)
        return INF;

    if(prevColor!=100500&&dyn[PLACE][prevColor][k]!=-1)
        return dyn[PLACE][prevColor][k];

    long long res = INF;

    if(a[PLACE]==0)
    {
        if(PLACE==0)
        {
            if(k==0)
                res = p[PLACE][prevColor];
            else
            if(k==1)
            {
                for(int i = 0; i<m; i++)
                    if(prevColor!=i)
                        res = min(res, p[PLACE][i]);
            }
        }
        else
        {
            if(prevColor==100500)
            {
                for(int i = 0; i<m; i++)
                {
                    res = min(res, get(PLACE-1, m, k-1, i)+p[PLACE][i]);
                }
            }
            else
            {
                for(int i = 0; i<prevColor; i++)
                {
                    res = min(res, get(PLACE-1, m, k-1, i)+p[PLACE][i]);
                }
                res = min(res, get(PLACE-1, m, k, prevColor)+p[PLACE][prevColor]);
                for(int i = prevColor+1; i<m; i++)
                {
                    res = min(res, get(PLACE-1, m, k-1, i)+p[PLACE][i]);
                }
            }
        }
    }
    else
    {
        if(PLACE==0)
        {
            if(k==0&&prevColor==a[PLACE]-1)
                res = 0;
            if(k==1&&prevColor!=a[PLACE]-1)
                res = 0;
        }
        else
        {
            res = get(PLACE-1, m, k-((a[PLACE]-1)!=prevColor), a[PLACE]-1);
        }
    }

    dyn[PLACE][m][k] = res;
    return res;

}

int main()
{

    ios::sync_with_stdio(false);
    ifstream cin("inp.txt");

    for(int i = 0; i<200; i++)
    for(int j = 0; j<200; j++)
    for(int k = 0; k<200; k++)
        dyn[i][j][k] = -1;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
        cin >> p[i][j];

    long long res = get(n-1, m, k, 100500);
    if(res>=INF)
        cout << -1;
    else
        cout << res;

    return 0;
}
