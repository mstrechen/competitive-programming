#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<iomanip>

using namespace std;

const int MAXN = 41;


long long dp0[MAXN][MAXN][MAXN][MAXN][2],
          dp1[MAXN][MAXN][MAXN][MAXN][2];



int cnt[4];



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    char c1, c2;

    cin >> n >> k;

    cin >> c1 >> c2;

    int head = (c1-'A')*2 + (c2-'A');

    for(int i = 0; i<n; i++)
    {
        cin >> c1 >> c2;
        cnt[(c1-'A')*2 + (c2-'A')]++;
    }

    dp0[0][0][0][0][head%2] = 1;

    for(int i = 0; i<k; i++)
    {
        for(int a00 = cnt[0]; a00>=0; a00--)
            for(int a01 = cnt[1]; a01>=0; a01--)
                for(int a10 = cnt[2]; a10>=0; a10--)
                        for(int a11 = cnt[3]; a11>=0; a11--)
                            if(a00+a10+a01+a11 == i)
                            {
                                long long tmp0 = dp0[a00][a01][a10][a11][0],
                                     tmp1 = dp0[a00][a01][a10][a11][1];
                                dp0[a00+1][a01][a10][a11][0]+= tmp0;
                                dp0[a00][a01+1][a10][a11][1]+=tmp0;
                                dp0[a00][a01][a10+1][a11][0]+=tmp1;
                                dp0[a00][a01][a10][a11+1][1]+=tmp1;
                            }
    }

    long long ans = 0;
    for(int a00 = cnt[0]; a00>=0; a00--)
            for(int a01 = cnt[1]; a01>=0; a01--)
                for(int a10 = cnt[2]; a10>=0; a10--)
                        for(int a11 = cnt[3]; a11>=0; a11--)
                            if(a00+a10+a01+a11 == k)
                                ans += dp0[a00][a01][a10][a11][head/2];


    if(ans)
        cout << "YES\n" << ans;
    else
        cout << "NO";
    return 0;
}
