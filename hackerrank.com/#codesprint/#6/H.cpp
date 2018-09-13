#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>


using namespace std;


pair<long long,long long> a;

vector<pair<int,long long> > dyn[100500];
int main()
{
    ios::sync_with_stdio(false);

    long long summDist = 0;
    int n,k;
    int tmp1,tmp2;
    cin >> n >> k;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].first >> a[i].second;

        if(a[i].first>a[i].second)
            swap(a[i].first, a[i].second);

        summDist+=abs(a[i].first-a[i].second);
    }
    if(n==k)
        cout << summDist;
    else
    {
        sort(a, a+n);
        for(int i = 0; i<n)
    }
    return 0;
}
