#include<iostream>
#include<vector>

using namespace std;

struct elem
{
    long long leftDiag, rightDiag, val;
    elem(long long lD = 0, long long rD = 0, long long val = 0, long long mod = 1):leftDiag(lD%mod),
                                                                               rightDiag(rD%mod),
                                                                               val(val%mod){}

    void divide(long long mod)
    {
        leftDiag%=mod;
        rightDiag%=mod;
        val%=mod;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, mod;


    cin >> m >> n >> mod;

    vector<elem> curLevel(n+2), nextLevel(n+2);

    for(int i = 1; i<=n; i++)
    {
        cin >> curLevel[i].val;
        curLevel[i].leftDiag = curLevel[i].rightDiag = curLevel[i].val;
    }

    for(int i = 1; i<m; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            nextLevel[j].val = curLevel[j].val + curLevel[j-1].leftDiag + curLevel[j+1].rightDiag;
            nextLevel[j].leftDiag = curLevel[j-1].leftDiag + nextLevel[j].val;
            nextLevel[j].rightDiag = curLevel[j+1].rightDiag + nextLevel[j].val;
            nextLevel[j].divide(mod);
            nextLevel[j].val*=2;
        }
        nextLevel.swap(curLevel);
    }

    for(int i = 1; i<=n; i++)
        cout << curLevel[i].val/2 << ' ';

    return 0;
}
