#include<iostream>
#include<algorithm>
#include<fstream>
#include<ctime>

using namespace std;

const long long suffixMod = 10000000;

long long a[77][77];

bool isOkNum[(int)suffixMod];

int n, m;

long long my_max(long long a, long long b)
{
    return a>b?a:b;
}

void findFineNumbers(int len, long long num)
{
    isOkNum[num] = 1;
    if(len==7)
        return;
    num*=10;
    findFineNumbers(len+1, num + 4);
    findFineNumbers(len+1, num + 7);
}

long long getAnsForNumber(long long a)
{
    if(isOkNum[a%suffixMod] && (a/suffixMod == 0 || isOkNum[a/suffixMod]))
        return a;
    return -1;
}


long long summsDown[10*1000];
int cSummsDown;

long long summsUp[10*1000];
int cSummsUp;


void dfsDown(int i, int j, long long current_summ)
{
    if(j<0||j>=m)
        return;
    current_summ+=a[i][j];
    if(i==n-1)
        summsDown[cSummsDown++] = current_summ;
    else
    {
        dfsDown(i+1, j+1, current_summ);
        dfsDown(i+1, j,   current_summ);
        dfsDown(i+1, j-1, current_summ);
    }
}

void dfsUp(int i, int j, long long current_summ)
{
    if(j<0||j>=m||i<0)
        return;
    current_summ+=a[i][j];
    if(i==0)
        summsUp[cSummsUp++] = current_summ;
    else
    {
        dfsUp(i-1, j+1, current_summ);
        dfsUp(i-1, j,   current_summ);
        dfsUp(i-1, j-1, current_summ);
    }
}

int main()
{
    //ifstream cin("inp.txt");
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin >> a[i][j];

    //double be = clock();
    findFineNumbers(1,4);
    findFineNumbers(1,7);


    long long ans = -1;

    int midV = (n-1)/2;

    for(int i = 0; i<m; i++)
    {
        cSummsUp = 0;
        cSummsDown = 0;

        dfsUp(midV-1, i, 0);
        dfsUp(midV-1, i-1, 0);
        dfsUp(midV-1, i+1, 0);

        dfsDown(midV, i, 0);

        if(cSummsDown == 0)
            summsDown[cSummsDown++] = 0;
        if(cSummsUp == 0)
            summsUp[cSummsUp++] = 0;

        for(int i = 0; i<cSummsDown; i++)
            for(int j = 0; j<cSummsUp; j++)
                ans = max(ans, getAnsForNumber(summsDown[i]+summsUp[j]));
    }

    //double en = clock();
    //cout << (en-be)/CLOCKS_PER_SEC << endl;

    cout << ans;


    return 0;
}
