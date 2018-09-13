#include<iostream>
#include<queue>
#include<string>

using namespace std;

#define s second
#define f front
#define w first
#define u string

u _(int a)
{
    int s = a%60,m;
    a/=60;
    m  = a%60;
    a/=60;
    u r;
    r+=(a/10+'0');
    r+=(a%10+'0');
    r+=':';
    r+=(m/10+'0');
    r+=(m%10+'0');
    r+=':';
    r+=(s/10+'0');
    r+=(s %10+'0');

    return r;
}

int r(u s)
{
    int r = 0;
    for(int i = 0; i<3; i++)
    {
        r*=60;
        r+=(s[i*3]-'0')*10+s[i*3+1]-'0';
    }
    return r;
}

int tt[1000][2];

u s;
queue<pair<int,int> > _q;



int main()
{
    for(int i = 0; i<1000; i++)
        tt[i][0] = -1;
    int n,k;
    cin >> n >> k;
    n/=k;

    u x;
    int y;
    int c = 0;

    pair<int,int> _tmp;

    for(int _i = 0; _i<n; _i++)
    {

        for(int _j = 0; _j<k; _j++)
        {
            cin >> x >> y;
            _q.push(make_pair(_i*k+_j, y));
        }
        c = max(c,r(x));
        tt[_i*k][0] = c;

        while(!_q.empty())
        {
            if(tt[_q.f().w][0]==-1)
                tt[_q.f().w][0]=c;

            if(_q.f().s>10)
            {
                _q.push(make_pair(_q.f().w,_q.f().s-10));
                c+=10;
            }
            else
            {
                c+=_q.f().s;
                tt[_q.f().w][1] = c;
            }
            _q.pop();
        }
        for(int _j = 0; _j<k; _j++)
        {
            cout << _(tt[_i*k+_j][0]) << ' '<<_(tt[_i*k+_j][1]) << endl;
        }

    }
    return 0;
}

