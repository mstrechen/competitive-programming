#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int SQRT = 333;

bool comp(const pair<pair<int,int>,int> & l, const pair<pair<int,int>,int> & r)
{
    if(l.first.first/SQRT==r.first.first/SQRT)
    {
        return l.first.second < r.first.second;
    }
    else
    {
        return l.first.first/SQRT < r.first.first/SQRT;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, k;
    cin >> n >> q >> k;

    vector<int> _A(n);

    for(auto & i : _A)
        cin >> i;

    vector<int> A(n+1);
    A[0] = 0;

    for(int i = 1; i<=n; i++)
        A[i] = _A[i-1]^A[i-1];


    vector<pair<pair<int,int>,int> > Q(q);

    int _i = 0;
    for(auto & i : Q)
    {
        cin >> i.first.first >> i.first.second;
        i.second = _i++;
    }
    sort(Q.begin(),Q.end(), comp);

    multiset<int> xors;






    return 0;
}
