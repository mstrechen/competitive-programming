#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int MOD = 1e9+9;

int findPrimesOnSegment(int left, int right, set<int> & toWrite)
{
    vector<char> allNumbers(right,1);

    for(int i = 4; i<right; i+=2)
        allNumbers[i] = 0;

    for(int i = 3; i*i<right; i+=2)
        if(allNumbers[i])
        {
            for(int j = 2; i*j<right; j++)
                allNumbers[i*j] = 0;
        }

    for(int i = left; i<right; i++)
        if(allNumbers[i])
            toWrite.insert(i);
}

int countOfVariants(int last2digits, int len, const set<int> & primes, vector<vector<int> > & memorized)
{
    if(memorized[len][last2digits]!=-1)
        return memorized[len][last2digits];
    if(len<3)
        return memorized[len][last2digits] = 1;

    int ans = 0;
    auto leftBound = primes.lower_bound((last2digits+1)*10);

    for(auto it = primes.lower_bound(last2digits*10); it!=leftBound; it++)
    {
        ans+=countOfVariants(*it % 100, len-1, primes, memorized);
        ans%=MOD;
    }
    return memorized[len][last2digits] = ans;
}

int main()
{
    vector<vector<int> > memorized(10000+1, vector<int>(100, -1));
    set<int> primes;

    findPrimesOnSegment(100,1000, primes);


    int len;
    cin >> len;

    int ans = 0;
    for(auto i : primes)
    {
        ans+=countOfVariants(i%100, len-1, primes, memorized);
        ans%=MOD;
    }

    cout << ans;




    return 0;
}
