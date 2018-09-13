#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

long long min(long long a, long long b)
{
    return a<b?a:b;
}

long long sign(long long a)
{
    if(a)
        return 1-2*(a<0);
    return 0;
}


struct comp
{
   bool operator ()(const pair<long long,int> & a, const pair<long long,int> & b)
{
     return abs(a.first)<abs(b.first)||(abs(a.first)==abs(b.first)&&a.second<b.second);
}
};

bool comp2(pair<long long,int> a, pair<long long,int> b)
{
     return a.second<b.second;
}

void makeGreater(vector<pair<long long, int> > & a, long long x, long long k)
{

    set<pair<long long, int>,comp> A(a.begin(), a.end());
    pair<long long,int> tmp;

    for(int i = 0; i<k; i++)
    {
        tmp = *A.begin();
        A.erase(A.begin());
        if(tmp.first>0)
            tmp.first+=x;
        else
            tmp.first-=x;
        A.insert(tmp);
    }
    a.assign(A.begin(), A.end());
}

void changeSign(long long & a, long long x, long long & k)
{
    if(a>0)
    {
        while(a>0)
        {
            k--;
            a-=x;
        }
        if(a==0&&k)
        {
            a-=x;
            k--;
        }
    }
    else
    {
        while(a<0)
        {
            k--;
            a+=x;
        }
        if(a==0&&k)
        {
            a+=x;
            k--;
        }
    }
}

void remake(vector<pair<long long, int> > & a, long long x, long long &k, int countOfZeroes, long long signWithoutZeroes)
{
    if((signWithoutZeroes==1&&countOfZeroes%2==0)||(signWithoutZeroes==-1&&countOfZeroes%2==1))
    {
        for(int i = 0; i<countOfZeroes; i++)
        {
            if(i==countOfZeroes-1)
                a[i].first+=x;
            else
                a[i].first-=x;
        }
    }
    else
    {
        for(int i = 0; i<countOfZeroes; i++)
        {
            a[i].first-=x;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    int n;
    long long x,k;

    cin >> n >> k >> x;

    vector<pair<long long, int> > a(n);

    long long resSign = 1;
    long long signWithoutZeroes=1;
    int countOfZeroes = 0;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        resSign*=sign(a[i].first);
        if(a[i].first)
        {
            signWithoutZeroes*=sign(a[i].first);
        }
        else
        {
            countOfZeroes++;
        }

    }
    sort(a.begin(), a.end(), comp());

    if(resSign==-1)
    {
        makeGreater(a, x, k);
    }
    else
    if(resSign == 1)
    {
        if(abs(a[0].first)<=x*k)
        {
            changeSign(a[0].first, x, k);
            sort(a.begin(), a.end(), comp());
            makeGreater(a,x,k);
        }
        else
        {
            if(a[0].first>0)
                a[0].first-=x*k;
            else
                a[0].first+=x*k;
        }

    }
    else
    {
        if(countOfZeroes<=k)
        {
            remake(a, x, k, countOfZeroes, signWithoutZeroes);
            k-=countOfZeroes;
            sort(a.begin(), a.end(), comp());
            makeGreater(a,x,k);
        }
    }
    sort(a.begin(), a.end(),comp2);

    for(auto i : a)
        cout << i.first << ' ';


    return 0;
}
