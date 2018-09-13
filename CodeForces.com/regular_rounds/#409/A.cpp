#include<iostream>
#include<iomanip>
#include<vector>
#include<cassert>

using namespace std;

double getMaxTime(const vector<int> & a, const vector<int> & b, double p)
{
    double l = 0, r = 1e12;

    do
    {
        double mid = (l+r)/2;
        double addEnergy = p*mid;

        for(int i = 0; i<(int)a.size(); i++)
        {
            addEnergy -= max(0.0, a[i] * mid - b[i]);
        }
        if(addEnergy < 0)
            r = mid;
        else
            l = mid;
    }
    while(l+1e-6 < r);

    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double sE = 0, p, P;

    cin >> n >> p;
    P = p;

    vector<int> A(n), B(n);
    for(int i = 0; i<n; i++)
    {
        int a, b;
        assert(cin >> a >> b);
        p -= a;
        sE += b;
        A[i] = a;
        B[i] = b;

    }

    cout.precision(10);
    if(p >= 0)
    {
        cout << -1;
    }
    else
    {
        cout << (fixed) << getMaxTime(A, B, P);
    }

    return 0;
}
