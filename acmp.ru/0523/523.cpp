#include<iostream>
#include<vector>

using namespace std;


int main()
{
    int n,k;

    cin >> n;
    vector<int> a(n);

    for(int i = 0; i<n; i++)
        cin >> a[i];

    cin >> k;
    int l = 0, r = 1e9;
    for(;l+1<r; )
    {
        int mid = (l+r-1)/2 + 1;
        int currSize = 0;
        int currCount = 0;
        bool flag = 0;
        for(auto i : a)
        {
            if(currSize+i>mid)
            {
                currCount++;
                currSize = 0;
            }
            if(i>mid)
                flag = 1;
            currSize+=i;
        }
        if(currSize)
            currCount++;

        if(currCount>k||flag)
            l = mid;
        else
            r = mid;
    }
    cout << r;

    return 0;
}
