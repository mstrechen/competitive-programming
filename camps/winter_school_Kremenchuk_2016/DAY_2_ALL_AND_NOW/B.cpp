#include<iostream>
#include<set>
#include<algorithm>
#include<functional>


using namespace std;

int inf = 2*1000*1000*1000;

void rec(int i, int n,int sum, vector<int> & A,const  vector<int> & source)
{
    if(i==n)
        A.push_back(sum*2);
    else
    {
        rec(i+1, n, sum,  A, source);
        rec(i+1, n, sum + source[i],  A,source);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;

    int allSum = 0;
    vector<int> candies(n);
    for(int i = 0; i<n; i++)
    {
        cin >> candies[i];
        allSum+=candies[i];
    }

    if(n==1)
    {
        cout << allSum;
        return 0;
    }


    9 24 30 93 490 | 12 78 9 0 2 90


    vector<int> possibleSummsA, possibleSummsB;

    rec(0,n/2,0,possibleSummsA, candies);
    rec(n/2,n,0,possibleSummsB, candies);

    int minAns = inf;
    sort(possibleSummsB.begin(),possibleSummsB.end());

    for(auto i : possibleSummsA)
    {
        auto it = lower_bound(possibleSummsB.begin(), possibleSummsB.end(), allSum-i);
        if(it!=possibleSummsB.end())
            minAns = min(minAns, abs(allSum - i - *it));
        if(it!=possibleSummsB.begin())
            minAns = min(minAns, abs(allSum - i - *(--it)));
    }

    cout << minAns;


    return 0;
}
