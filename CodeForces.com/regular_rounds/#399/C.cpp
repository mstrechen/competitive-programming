#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    vector<int> cntCur(1024,0), cntNext(1024,0);

    int n, k, x;

    cin >> n >> k >> x;

    for(int i = 0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        cntCur[tmp]++;
    }

    for(int i = 0; i<k; i++)
    {
        int pairty = 0;
        cntNext.assign(1024,0);
        for(int j = 0; j<1024; j++)
        {
            if(pairty)
            {
                pairty^=(cntCur[j]%2);
                if(cntCur[j])
                {
                    cntCur[j]--;
                    cntNext[j]++;
                }
            }
            else
            {
                pairty^=(cntCur[j]%2);
            }
            cntNext[j]+=cntCur[j]/2;
            cntNext[j^x]+=(cntCur[j]+1)/2;
        }
        cntCur.swap(cntNext);
    }

    bool flag = 1;
    int i = 1023;
    while(flag)
    {
        if(cntCur[i] != 0)
        {
            cout << i << ' ';
            flag = 0;
        }
        i--;
    }

    flag = 1;
    i = 0;

    while(flag)
    {
        if(cntCur[i] != 0)
        {
            cout << i;
            flag = 0;
        }
        i++;
    }

    return 0;
}
