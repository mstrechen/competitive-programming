#include<iostream>
#include<vector>

using namespace std;

struct currentStep
{
    int first,second;

    currentStep(int first, int second):first(first),second(second){}
    currentStep(bool isDefined = 1)
    {
        if(isDefined)
        {
            first = 0;
            second = 0;
        }
        else
        {
            first = -1;
            second = 0;
        }
    }

    bool isDefined() const
    {
        return first!=-1;
    }
};

currentStep operator + (const currentStep & a, const int & b)
{
    if(a.isDefined())
        return currentStep(a.second+b, a.first);
    return a;
}

currentStep max(const currentStep & a, const currentStep & b)
{
    if(a.isDefined()&&b.isDefined())
        return (a.first>b.first)?
                    (a) : ((a.first<b.first||a.second>b.second)? b : a);
    else
        if(a.isDefined())
            return a;
    return b;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, maxSize;

    cin >> n;

    vector<int> numbers(n);

    for(auto& i : numbers)
        cin >> i;

    cin >> maxSize;

    vector<vector<currentStep> > dp(n+1,vector<currentStep>(maxSize,currentStep()));

    for(int i = n-1; i>=0; i--)
    {
        int currentSum = 0;
        for(int j = 0; j<maxSize; j++)
        {
            if(i+j>=n)
                dp[i][j] = currentStep(false);
            else
            {
                currentSum+=numbers[i+j];
                for(int k = 0; k<=j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i+j+1][k]);
                }
                dp[i][j]=dp[i][j]+currentSum;
            }
        }
    }

    currentStep res(false);
    for(auto i : dp[0])
    {
        res = max(i,res);
    }
    cout << res.first;

    return 0;
}
