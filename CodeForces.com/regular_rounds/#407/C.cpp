#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> A(n);


    for(auto & i : A)
        cin >> i;
    long long maxSum = abs(A[0] - A[1]);

    vector<long long> new_A(n-1);
    for(int i = 0; i+1<n; i++)
    {
        new_A[i] = abs(A[i] - A[i+1]);
    }

    long long minPrefix0 = 0, maxPrefix1 = new_A[0];
    long long sum = 0;

    for(int i = 0; i+1<n; i++)
    if(i&1)
    {
        sum -= new_A[i];
        maxSum = max(maxSum, sum - minPrefix0);
        maxSum = max(maxSum, -(sum - maxPrefix1));
        minPrefix0 = min(minPrefix0, sum);

    }
    else
    {
        sum += new_A[i];
        maxSum = max(maxSum, sum - minPrefix0);
        maxSum = max(maxSum, -(sum - maxPrefix1));
        maxPrefix1 = max(maxPrefix1, sum);
    }

    cout << maxSum;

    return 0;
}
