#include<iostream>
#include<cmath>


using namespace std;

long long getCount(long long n)
{
    long long D = 1 + 8*n, tmp;
    tmp = sqrt(D);
    if(tmp*tmp==D)
    {
        return (1+tmp)/2;
    }
    else
    {
        return -1;
    }

}


int main()
{
    ios::sync_with_stdio(false);

    long long a00, a01, a10, a11;

    cin >> a00  >> a01 >> a10 >> a11;

    long long zeroes, ones;
    zeroes = getCount(a00);
    ones = getCount(a11);

    if(a01+a10==0&&zeroes!=-1&&ones!=-1&&(a00==0||a11==0))
    {
        if(a00==0)
        {
            for(int i = 0; i<ones; i++)
                cout << 1;
        }
        else
        {
            for(int i = 0; i<zeroes; i++)
                cout << 0;
        }
        return 0;
    }

    if(zeroes==-1||ones==-1||((a10+a01)!=(zeroes*ones)))
    {
        cout << "Impossible";
        return 0;
    }
    int place1 = a01/ones;

    if(place1*ones==a01)
    {
        for(int i = 0; i<place1; i++)
            cout << 0;
        for(int i = 0; i<ones; i++)
            cout << 1;
        for(int i = place1; i<zeroes; i++)
            cout << 0;
    }
    else
    {
        for(int i = 0; i<place1; i++)
            cout << 0;
        for(int i = 0; i<ones-a01%ones; i++)
            cout << 1;
        cout << 0;
        for(int i = 0; i<a01%ones; i++)
            cout << 1;
        for(int i = place1+1; i<zeroes; i++)
            cout << 0;

    }

    return 0;
}
