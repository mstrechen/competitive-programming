#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void makePrimes(int n, vector<int> & p)
{
    vector<char> sieve(n+1, 0);
    for(int i = 2; i*i<=n; i++)
    if(sieve[i] == 0)
    {
        for(int j = i*2; j<=n; j+=i)
            sieve[j] = 1;
    }

    for(int i = 2; i<=n; i++)
        if(sieve[i] == 0)
            p.push_back(i);
}

int getcnt(int val, vector<int> & p)
{
    return p.end() - lower_bound(p.begin(), p.end(), val*2);
}

int getKth(int val, long long k, vector<int> & p)
{
    val*=2;
    for(auto i : p)
    {
        if(i>=val)
            k--;
        if(k == 0)
            return i;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxB;
    cin >> maxB;

    vector<int> p;

    makePrimes(maxB, p);

    long long k;
    cin >> k;

    int maxPrime = p.back();

    int tmp = 0, i = 0;
    do
    {
        k-=tmp;
        i++;
        tmp = getcnt(i, p);
    }
    while(tmp && k>tmp);

    if(tmp == 0)
    {
        cout << "-1 -1";
        return 0;
    }

    cout << i << ' ' << getKth(i, k, p)-i;

    return 0;
}
