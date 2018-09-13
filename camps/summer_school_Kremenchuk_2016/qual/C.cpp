#include<iostream>
#include<fstream>

using namespace std;

string s;
string timeToString(int m)
{
    s = "";
    s+=(m/60)/10+'0';
    s+=(m/60)%10+'0';
    s+=':';
    s+=(m%60)/10+'0';
    s+=(m%10)+'0';
    return s;
}

int d[2];
int main()
{
    ifstream cin("time.in");
    ofstream cout("time.out");

    int m, d1,d2,k;

    cin >> m >> d[0] >> d[1] >> k;
    int day = 0;
    k+=m;
    for(int i = m; i<k; i++)
    {
        if(d[day]==1&&m>=120)
        {
            d[day] = 0;
            m+=60;
        }
        else
        if(d[day]==-1&&m>=180)
        {
            d[day] = 0;
            m-=60;
        }
        day+=m/1440;
        m%=1440;
        cout << timeToString(m) << endl;
        m++;
    }

    return 0;
}
