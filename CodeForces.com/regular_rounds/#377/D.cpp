#include<iostream>
#include<vector>
#include<numeric>

using namespace std;


bool check(vector<int> & a, vector<int> & used, vector<int> &toWork ,int r)
{
    int needToWork = 0;
    used.assign(toWork.size(), 0);

    int uSize =0;
    for(int i = r; i>=0; i--)
    {
        if(a[i]==0||used[a[i]]==1)
        {
            if(needToWork>0)
                needToWork--;
        }
        else
        {
            needToWork+=toWork[a[i]];
            used[a[i]] = 1;
            uSize++;
        }
    }
    if(needToWork)
        return false;
    return uSize == toWork.size()-1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;


    vector<int> a(n,0);
    vector<int> used(k+1,0);
    vector<int> needToWork(k+1,0);

    for(int i = 0; i<n; i++)
        cin >> a[i];
    for(int i = 1; i<=k; i++)
        cin >> needToWork[i];


    if(!check(a,used, needToWork,n-1))
    {
        cout << -1;
        return 0;
    }

    int l = 0, r = n-1;

    while(l+1<r)
    {
        int mid = (l+r-1)/2 + 1;
        if(check(a,used,needToWork, mid))
            r = mid;
        else
            l = mid;
    }
    cout << (l+r-1)/2 + 2;

    return 0;
}
