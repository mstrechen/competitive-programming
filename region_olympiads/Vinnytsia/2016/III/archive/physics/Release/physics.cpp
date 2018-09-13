#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 123456;

int cnt[MAXN + 5];

void minn(int & a, int b)
{
    if(b<a)
        a = b;
}
void maxx(int & a, int b)
{
    if(b>a)
        a = b;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int x;
    int maxVal = 0;
    int minVal = MAXN + 5;

    for(int i = 0; i<n; i++)
    {
        cin >> x;
        cnt[x]++;
        maxx(maxVal, x);
        minn(minVal, x);
    }

    for(int i = minVal; i<=maxVal; i++)
        if(cnt[i])
            for(int j = cnt[i]; j>0; j--)
                cout << i << ' ';

    for(int i = minVal; i<=maxVal; i++)
        cnt[i]+=cnt[i-1];

    for(int i = 1; i<=maxVal; i++)
        cout << n - cnt[i-1] << ' ';



    return 0;
}
