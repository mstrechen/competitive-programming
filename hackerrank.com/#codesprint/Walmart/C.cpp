#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long getLittleAns(long long a, long long pattern, long long delta)
{
    if(a < delta*100)
        return 0;
    long long ans = (a/(delta*1000))*delta;

    if(a%(delta*1000) >= pattern*delta)
    {
        if(pattern/100 || a>=1000)
            ans+=(a%delta + 1);
    }

    return ans;

}

long long getAns(long long a, vector<int> triplets)
{
    long long delta = 1;
    int i = 0;

    long long ans = 0;

    while(i<=12)
    {
        for(auto j : triplets)
            ans+=getLittleAns(a, j, delta);
        i++;
        delta*=10;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;

    cin >> a >> b;

    vector<int> triplets;
    for(int i = 0; i<1000; i++)
    {
        if((i%10 > (i/10)%10 && (i/100)%10 > (i/10)%10)||
           (i%10 < (i/10)%10 && (i/100)%10 < (i/10)%10))
           triplets.push_back(i);
    }

    cout << getAns(b,triplets) - getAns(a-1,triplets);


    return 0;
}
