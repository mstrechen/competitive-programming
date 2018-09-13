#include<iostream>
#include<iomanip>
#include<map>

using namespace std;

int getMin(map<int,int> & a)
{
    int tmp = a.begin()->first;
    if(a.begin()->second==1)
        a.erase(a.begin());
    else
        a.begin()->second--;
    return tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int,int> a;

    int n;
    cin >> n;

    int x;
    for(int i = 0; i<n; i++)
    {
        cin >> x;
        a[x]++;
    }
    double res = 0;
    for(int i = 1; i<n; i++)
    {
        x = getMin(a)+getMin(a);
        res+=x*0.05;
        a[x]++;
    }
    cout << (fixed) << setprecision(2) << res;
    return 0;
}
