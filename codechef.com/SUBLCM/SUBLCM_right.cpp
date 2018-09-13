#include<stdio.h>
#include<bitset>
#include<vector>
#include<set>

using namespace std;

int sieve[1000500];

void makeSieve(int n)
{
    sieve[1] = 1;
    for(int i = 2; i<=n; i++)
    {
        if(!sieve[i])
        {
            for(int j = n/i; j; j--)
                sieve[j*i] = i;
        }
    }
}

int a[1000000];
bitset<1000500> dividers;

char c = 0;
void scan(int & n)
{
    n = 0;
    while(c<'0')
        c = getchar();
    while('0'<=c&&c<='9')
    {
        n*=10;
        n+=c-'0';
        c = getchar();
    }
}

int main()
{
    int _n;

    makeSieve(1000400);

    scan(_n); //

    for(int i = 0; i<_n; i++)
    {
        int n,maxAns = 0;
        scan(n);
        dividers.reset();
        int tmp;
        int r = 0;

        for(int i = 0; i<n; i++)
        {
            scan(tmp);
            a[i] = tmp;
            int lastUsed = 0;
            while(tmp>1)
            {
                if(lastUsed!=sieve[tmp])
                while(dividers[sieve[tmp]])
                {
                        int tmp1 = a[r++];
                        while(tmp1>1)
                        {
                            dividers[sieve[tmp1]] = 0;
                            tmp1/=sieve[tmp1];
                        }
                }
                lastUsed = sieve[tmp];
                dividers[sieve[tmp]] = 1;
                tmp/=sieve[tmp];
            }
            maxAns = max(maxAns, i-r);
        }
        printf("%d\n", (maxAns?maxAns+1:-1));
    }

    return 0;
}

