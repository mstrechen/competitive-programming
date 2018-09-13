#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

vector<pair<string, long long> > pals;

const long long delta = 100001;
const long long mod = 1000000007;

string s;

long long F[100500], st[100500];


long long f(int l, int r)
{
    if(l==0)
        return F[r];

    long long ans = (F[r]-F[l-1]*st[r-l+1])%mod;
    if(ans<0)
        ans+=mod;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);


    int n, q;
    cin >> n >> q;
    cin >> s;

    F[0] = s[0];
    st[0] = 1;

    for(int i = 1; i<s.size(); i++)
    {
        st[i] = (st[i-1]*delta)%mod;
        F[i] = (F[i-1]*delta+s[i])%mod;
    }

    for(int i = 0; i<n; i++)
    {
        int l = i, r = i;
        for(;l>=0&&r<n&&s[l]==s[r]; l--,r++)
        {
            pals.push_back(make_pair(string(s.begin()+l,s.begin()+r+1), f(l,r)));
        }
        l = i, r = i+1;
        for(;l>=0&&r<n&&s[l]==s[r]; l--,r++)
        {
            pals.push_back(make_pair(string(s.begin()+l,s.begin()+r+1), f(l,r)));
        }
    }
    sort(pals.begin(), pals.end());

    for(int i = 0; i<q; i++)
    {
        cin >> n;
        if(pals.size()<n)
            cout << -1 << '\n';
        else
            cout << pals[n-1].second << '\n';
    }

    return 0;
}
