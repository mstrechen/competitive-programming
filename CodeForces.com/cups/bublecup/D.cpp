#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 128;

vector<double> getProb(vector<double> a, vector<double> b)
{
    vector<double> res(MAXN, 0);
    for(int i = 0; i<MAXN; i++)
    {
        for(int j =0; j<MAXN; j++)
            res[i^j]+= a[i]*b[j];
    }
    return res;
}

vector<double> sqr(vector<double> a)
{
    return getProb(a,a);
}

vector<double> binpow(vector<double> a, int x)
{
    if(x==1)
        return a;
    if(x&1)
        return getProb(binpow(a,x-1),a);
    return sqr(binpow(a,x/2));
}

int main()
{
    ios::sync_with_stdio(false);

    int n, x;
    vector<double> a(MAXN);

    cin >> n >> x;
    for(int i = 0; i<=x; i++)
        cin >> a[i];

    a = binpow(a,n);

    cout.precision(10);

    cout << (fixed) << 1-a[0];


    return 0;
}
