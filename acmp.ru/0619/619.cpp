#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main()
{
    int n, sum;

    cin >> n >> sum;

    vector<double> dpCur(n*6+1,0), dpNext(n*6+1,0);

    dpCur[0] = 1;

    for(int i = 0; i<n; i++)
    {
        for(int j = i; j<=i*6; j++)
            for(int delta = 1; delta<=6; delta++)
                dpNext[j+delta]+=dpCur[j]/6;
        dpNext.swap(dpCur);
        dpNext.assign(n*6+1, 0);
    }
    cout.precision(10);
    cout << dpCur[sum];
    return 0;
}
