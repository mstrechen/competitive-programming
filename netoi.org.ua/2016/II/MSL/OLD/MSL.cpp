#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

long long a[77][77];
int n, m;

long long my_max(long long a, long long b)
{
    return a>b?a:b;
}

long long getAnsForNumber(long long a)
{
    long long cpy_a = a;
    if(a==0)
        return -1;
    while(a)
    {
        if(a%10!=7 && a%10!=4)
            return -1;
        a/=10;
    }
    return cpy_a;
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
        return my_max(my_max(dfs(i+1, j+1, current_summ),
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

    double be = clock();
    long long ans = -1;
    for(int i = 0; i<m; i++)
        ans = my_max(dfs(0,i,0), ans);

    double en = clock();

    //cout << (en-be)/CLOCKS_PER_SEC << endl;

    cout << ans;


    return 0;
}
