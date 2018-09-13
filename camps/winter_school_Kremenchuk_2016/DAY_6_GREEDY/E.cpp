#include<iostream>
#include<set>

using namespace std;

const long long oo = 1000000000LL * 1000000000LL;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multiset<long long> N,M;
    long long Nsumm = 0, Msumm = 0;

    int n,m;

    long long ans = 0;

    cin >> n >> m;

    for(int i = 1; i<n; i++)
    {
        int x;
        cin >> x;
        N.insert(x);
        Nsumm+=x;

    }
    for(int i = 1; i<m; i++)
    {
        int x;
        cin >> x;
        M.insert(x);
        Msumm+=x;
    }

    while((!N.empty())||(!M.empty()))
    {
        long long ansForN, ansForM;
        if(N.empty())
        {
            ansForN = +oo;
        }
        else
        {
            ansForN = Msumm*(n-N.size())+ (*N.rbegin())*(m-M.size()-100500500);
        }
        if(M.empty())
        {
            ansForM = +oo;
        }
        else
        {
            ansForM = Nsumm*(m-M.size()) + (*M.rbegin())*(n-N.size()-100500500);
        }

        if(ansForN < ansForM)
        {
            ans+=(*N.rbegin())*(m-M.size());
            Nsumm-=*N.rbegin();
            N.erase(N.find(*N.rbegin()));
        }
        else
        {
            ans+=(*M.rbegin())*(n-N.size());
            Msumm-=*M.rbegin();
            M.erase(M.find(*M.rbegin()));
        }
    }

    cout << ans;





    return 0;
}
