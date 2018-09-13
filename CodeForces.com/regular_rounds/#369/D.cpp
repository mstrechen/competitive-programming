#include<iostream>
#include<cmath>
#include<set>

using namespace std;

long long ans = 1;
long long used = 0;
const long long MOD = 1000000007;

int step[2*100500];
int ioi[2*100500];
set<pair<int,int> > A,B;




long long sqr(long long x)
{
    return (x*x)%MOD;
}


long long pow2(long long x)
{
    if(x==0)
        return 1;
    if(x&1)
    {
        return 2*pow2(x-1)%MOD;
    }
    else
    {
        return sqr(pow2(x/2));
    }
}




void DFS(int i, int sstep, int IOI)
{
    cout << i << sstep << endl;
    if(step[i]!=0)
    {
        if(ioi[i]==IOI)
        {
         ans*=pow2(sstep-step[i]) - 2;
         ans%=MOD;
         used+=sstep-step[i];
        }
    }
    else
    {

        step[i] = sstep;
        ioi[i] = IOI;
        pair<int,int> tmp;
       while(A.lower_bound({i,-1})!=A.end())
       {

           tmp = *A.lower_bound({i,-1});
           A.erase(tmp);
           B.erase({tmp.second, tmp.first});
           DFS(tmp.second, sstep+1, IOI);

       }
       while(B.lower_bound({i,-1})!=B.end())
       {
           tmp = *B.lower_bound({i,-1});
           B.erase(tmp);
           A.erase({tmp.second, tmp.first});
           DFS(tmp.second, sstep+1, IOI);
       }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int tmp;
    for(int i = 0; i<n; i++ )
    {
        cin >> tmp;
        A.insert({i,tmp-1});

        B.insert({tmp-1, i});
    }
    for(int i = 0; i<n; i++)
    {
        if(step[i]==0)
            DFS(i, 1, i+1);
    }
    ans*=pow2(n-used);
    ans%=MOD;
    if(ans<0)
        ans+=MOD;
    cout << ans;


    return 0;
}
