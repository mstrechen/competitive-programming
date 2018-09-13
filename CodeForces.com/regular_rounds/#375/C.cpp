#include<iostream>
#include<vector>
#include<map>
#include<functional>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int a[4000], b[4000];
    vector<int> used(n+1,0);
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        if(a[i]>m)
            a[i] = 0;
        used[a[i]]++;
    }
    bool flag = 1;
    int minValue = n/m;
    int replaces = 0;
    while(flag)
    {
        flag = 0;
        int currmin = 1, currmax = 1;
        for(int i = 1; i<=m; i++)
        {
            if(used[i]<used[currmin])
                currmin = i;
        }
        if(used[currmin]<minValue)
        {
            replaces++;
            flag = 1;
            if(used[0]>0)
            {
                for(int i = 0; i<n; i++)
                {
                    if(a[i]==0)
                    {
                        a[i] = currmin;
                        used[currmin]++;
                        used[0]--;
                        break;
                    }
                }
            }
            else
            {
                for(int i = 1; i<=m; i++)
                {
                    if(used[i]>used[currmax])
                        currmax = i;
                }
                for(int i = 0; i<n; i++)
                {
                    if(a[i]==currmax)
                    {
                        a[i] = currmin;
                        used[currmin]++;
                        used[currmax]--;
                        break;
                    }
                }
            }
        }

    }
    cout << minValue << ' ' << replaces << '\n';
    for(int i = 0; i<n; i++)
    {
        if(a[i])
            cout << a[i];
        else
            cout << b[i];
        cout << ' ';
    }

    return 0;
}
