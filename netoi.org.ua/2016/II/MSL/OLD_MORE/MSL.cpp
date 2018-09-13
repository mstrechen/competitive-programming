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



long long dfs(int i, int j, long long current_summ)
{
    if(j<0||j>=m)
        return -1;

    current_summ+=a[i][j];
    if(i==n-1)
        return getAnsForNumber(current_summ);
    else
    {
        return max(max(dfs(i+1, j+1, current_summ),
                       dfs(i+1, j,   current_summ)),
                       dfs(i+1, j-1, current_summ));
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

    m = 12;
    n = 12;

    long long ans = -1;
    for(int i = 0; i<m; i++)
        ans = max(dfs(0,i,0), ans);

    //double en = clock();
    //cout << (en-be)/CLOCKS_PER_SEC << endl;

    cout << ans;


    return 0;
}
