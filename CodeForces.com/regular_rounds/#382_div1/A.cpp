#include<iostream>
#include<cmath>

using namespace std;

long long minimize[1000];


long long minimizeCount(long long depth)
{
    if(minimize[depth])
        return minimize[depth];
    if(depth==0)
        return minimize[depth]=1;
    if(depth==1)
        return minimize[depth]=2;
    return minimize[depth] = minimizeCount(depth-1)+minimizeCount(depth-2);

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long n;
    cin >> n;

    long long l = 0, r = 2*log2(n);
    while(l<r-1)
    {
        long long mid = (l+r)/2;
        if(minimizeCount(mid)>n)
            r = mid;
        else
            l = mid;

    }
    cout << l;
    return 0;
}
