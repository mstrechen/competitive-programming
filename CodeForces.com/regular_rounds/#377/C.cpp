#include<iostream>


using namespace std;

long long _max(long long a, long long b)
{
    return a>b?a:b;
}
long long _max(long long a, long long b,long long c)
{
    return _max(a,_max(b,c));
}
long long _min(long long a, long long b)
{
    return a<b?a:b;
}
long long _min(long long a, long long b, long long c)
{
    return _min(a,_min(b,c));
}

long long get(long long a, long long b, long long c, int be)
{
    long long days = _max(a,b,c);
    if(be==1)
    {
        return _min((days-a + _max(days-b,0)+ _max(days-c,0) ),
                   (days-a + _max(days-b,0)+ _max(days-c-1,0) ),
                   (days-a + _max(days-b-1,0)+ _max(days-c-1,0) ));
    }
    else
    if(be==2)
    {
        return _min((_max(days-a,0) + _max(days-b,0)+ _max(days-c,0) ),
                   (_max(days-a-1,0) + _max(days-b,0)+ _max(days-c,0) ),
                   (_max(days-a-1,0) + _max(days-b,0)+ _max(days-c-1,0) ));
    }
    else
    {
        return _min((_max(days-a,0) + _max(days-b,0)+ _max(days-c,0) ),
                   (_max(days-a,0) + _max(days-b-1,0)+ _max(days-c,0) ),
                   (_max(days-a-1,0) + _max(days-b-1,0)+ _max(days-c,0) ));
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long _minAns = 3*1000ll*1000*1000*1000*1000*1000;

    long long a,b,c;

    cin >> a >> b >> c;

    for(int i = 1; i<=3;i++)
        _minAns = _min(_minAns, get(a,b,c,i));

        cout << _minAns;

    return 0;
}
