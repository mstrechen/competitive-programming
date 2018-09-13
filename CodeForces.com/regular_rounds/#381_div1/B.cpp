#include<iostream>
#include<functional>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<set>

using namespace std;
using namespace __gnu_pbds;



typedef tree<pair<long long,long long>,null_type,less<pair<long long,long long> >,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<pair<long long, ordered_set * > > st;

vector<vector<pair<int,int> > > e;
vector<long long> a;
vector<int> res;

void mergeThis(pair<long long, ordered_set * > & a, pair<long long, ordered_set * > & b)
{
    if(b.second->size()>a.second->size())
        swap(a,b);
    long long delta = a.first-b.first;
    for(auto i : *b.second)
    {
        a.second->insert({i.first+delta,i.second});
    }
    b.second->clear();
}



void dfs(int depth, int v, long long len)
{
    if(st.size()<=depth)
        st.push_back({0, new ordered_set});
    for(auto i : e[v])
    {
        dfs(depth+1, i.first, i.second);
        mergeThis(st[depth], st[depth+1]);
    }
    res[v] = st[depth].second->size() - st[depth].second->order_of_key({st[depth].first,-1});
    st[depth].second->insert({a[v]+st[depth].first,v});
    st[depth].first+=len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    e.assign(n,{});
    a.assign(n,0);
    res.assign(n,0);

    for(int i = 0; i<n; i++)
        cin >> a[i];

    int tmpP, tmpW;
    for(int i = 0; i<n-1; i++)
    {
        cin >> tmpP >> tmpW;
        e[tmpP-1].push_back({i+1,tmpW});
    }
    dfs(0, 0, 0);

    for(auto i : res)
        cout << i << ' ';



    return 0;
}
