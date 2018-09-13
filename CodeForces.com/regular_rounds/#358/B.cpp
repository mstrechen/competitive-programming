#include<iostream>
#include<map>

using namespace std;


map<int, int> a;

void makeLess(int _a)
{
    a[_a]--;
    if(a[_a]==0)
        a.erase(_a);
}

int main()
{
    ios::sync_with_stdio(false);

    int n,tmp,ans;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    for(ans = 1; ans<(*a.rbegin()).first; ans++)
    {
        if(a[ans]==0)
        {
            makeLess((*a.upper_bound(ans)).first);
            a[ans] = 1;
        }
    }
    if(a[ans]==0)
        cout << ans;
    else
        cout << ans+1;
    return 0;
}
