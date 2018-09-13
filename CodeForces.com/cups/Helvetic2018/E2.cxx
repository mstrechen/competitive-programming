#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
/*

using namespace std;

long long k1[5001],k2[5001];

int a[500005];
bool used[500005];

int main()
{

    k1[0] = 1;
    int k,n;
    long long pr,c;

    cin>>k>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];

    sort(a,a+n);
    vector<int> diff(n - 1);
    for(int i = 1; i < n; i++)
        diff[i - 1] = a[i] - a[i - 1];
    nth_element(diff.begin(), diff.begin() + k*2 - 1, diff.end());
    multiset<int> d(diff.begin(), diff.begin() + k*2 - 1);
    
    for(int i = 1; i < n; i++){
        if(d.count(a[i] - a[i - 1])){
            d.erase(d.find(a[i] - a[i - 1]));
            used[i] = 1;
            used[i - 1] = 1;
        }
    }


    pr = a[0];
    for(int j=0;j<=k;++j)
        k1[j]=k2[j] = 2e9;

    k1[0] = 0;
    bool flag = 1;

    for(int i=1;i<n;++i)
    if(used[i]){
        flag = 1;
        c = a[i];

        for(int j=k;j>0;--j){
            k1[j] = min(k1[j],k2[j]);

            k2[j] = min(k1[j-1]+c-pr,k1[j]);}

        pr = c;
    } else {
        if(flag == 1){
            for(int j = k; j > 0; j--)
                k1[j] = min(k1[j],k2[j]);
                
            flag = 0;
        }
        pr = a[i];
    }

    cout<<min(k1[k],k2[k]);
}*/