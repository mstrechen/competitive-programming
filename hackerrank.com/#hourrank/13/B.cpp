#include<iostream>
#include<cmath>
#include<bitset>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long count = 0;
    int countOfPrime = 0;
    cin >> n;
    long long sq = sqrt(n+1)+2;
    vector<bitset<300> > sieve(sq+2,0);

    for(int i = 2; i<=n; i++)
    {
        long long tmp = (1<<sieve[i])-2;
        if(tmp>0)
            count+=tmp/2;

        if(sieve[i]==0)
        {
            for(int j = 2; i*j<=n; j++)
            {
                sieve[i*j]++;
            }
        }
    }
    cout << count;
    return 0;
}
