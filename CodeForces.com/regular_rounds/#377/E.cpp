#include<iostream>
#include<functional>
#include<vector>
#include<set>
#include<map>

using namespace std;

struct conny
{
    int cost, user, i;
    conny(int cost = 0, int user = 0,int i = 0):cost(cost), user(user), i(i){};

    bool operator () (const conny & a, const conny & b)
    {
        if(a.user==0&&b.user!=0)
            return 1;
        if(a.user!=0&&b.user==0)
            return 0;

        int x=(a.user==0)*10000 + a.cost;
        int y=(b.user==0)*10000 + b.cost;

        if(x==y)
            return a.i<b.i;
        return x>y;
    }

};
map<int, set<conny,conny> > a;

set<pair<int, int>, greater<pair<int,int> > > sockets;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    int tmp;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        a[tmp].insert(conny(0,0,i));
    }
    for(int i = 1; i<=m; i++)
    {
        cin >> tmp;
        sockets.insert({tmp,i});
    }
    long long ans = 0,ansCount = 0;
    conny temp,temp1;
    while(!sockets.empty())
    {
        int x = sockets.begin()->first;
        int y = sockets.begin()->second;
        sockets.erase({x,y});
        int currentCost = 0;


        bool flag = 1;
        do
        {
            if(a.count(x)&&!a[x].empty())
            {
                if(a[x].begin()->user==0)
                {
                    flag = 0;
                    temp = *a[x].begin();
                    a[x].erase(temp);
                    temp.user = y;
                    temp.cost = currentCost;
                    a[x].insert(temp);

                    ans+=currentCost;
                    ansCount++;
                    flag = 0;
                }
                else
                if(a[x].begin()->cost>currentCost)
                {
                    temp = *a[x].begin();
                    temp1 = temp;
                    ans+=currentCost;
                    ans-=temp.cost;

                    a[x].erase(temp);
                    temp1.user = y;
                    temp1.cost = currentCost;
                    a[x].insert(temp1);
                    y = temp.user;
                    currentCost = temp.cost;
                }
            }
            if(x==1)
                x = 0;
            if(flag)
            {
                currentCost++;
                x = (x>>1)+(x&1);
            }

        }
        while(x&&flag);
    }
    vector<int> comps(n+1,0);
    vector<int> slots(m+1,0);

    for(int i = 1; i<=200000; i++)
        for(conny it : a[i])
        if(it.user!=0)
        {
            comps[it.i] = it.user;
            slots[it.user] = it.cost;
        }
    cout << ansCount << ' ' << ans << '\n';
    for(int i = 1; i<=m; i++)
        cout << slots[i] << ' ';
    cout << '\n';
    for(int i = 0; i<n; i++)
        cout << comps[i] << ' ';




    return 0;
}
