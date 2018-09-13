#include<iostream>
#include<vector>

using namespace std;


int main()
{
    int n,k;

    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i<n; i++)
        cin >> a[i];

    int l = 0, r = 1000000000;
    for(; l+1<r; )
    {
        int mid = (l+r)/2;
        int currCount = 0;
        for(auto i : a)
            currCount+=i/mid;
        if(currCount<k)
            r = mid;
        else
            l = mid;
    }
    cout << l << endl;

    return 0;
}
