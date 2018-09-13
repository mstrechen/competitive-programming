#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int DAY = 24*60*60*1000;

struct record
{
    string _time, _type;
    int _timeInMs;
    record(const string & time = "00:00:00:000", const string & type = "?") : _time(time), _type(type)
    {
        int hh = (time[0]-'0')*10 + (time[1]-'0');
        int mm = (time[3]-'0')*10 + (time[4]-'0');
        int ss = (time[6]-'0')*10 + (time[7]-'0');
        int ms = (time[9]-'0')*100 + (time[10]-'0')*10 + (time[11]-'0');
        _timeInMs = ms + 1000*(ss + 60*(mm + 60*hh));
    }

    record(int source)
    {
        _type = "?";
        if(source<0)
            source += DAY;
        _timeInMs = source;

        int ms = source%1000;
        source/=1000;
        int ss = source%60;
        source/=60;
        int mm = source%60;
        source/=60;
        int hh = source;

        _time.push_back('0' + hh/10);
        _time.push_back('0' + hh%10);
        _time.push_back(':');
        _time.push_back('0' + mm/10);
        _time.push_back('0' + mm%10);
        _time.push_back(':');
        _time.push_back('0' + ss/10);
        _time.push_back('0' + ss%10);
        _time.push_back(':');
        _time.push_back('0' + ms/100);
        _time.push_back('0' + (ms/10)%10);
        _time.push_back('0'+ ms%10);
    }
};

record operator - (const record & a, const record & b)
{
    return record(a._timeInMs-b._timeInMs);
}
record operator + (const record & a, const record & b)
{
    return record(a._timeInMs+b._timeInMs);
}

bool operator < (const record & a, const  record & b)
{
    return a._timeInMs < b._timeInMs;
}

istream & operator >> (istream & in, record & a)
{
    string time, type;
    in >> time >> type;

    a = record(time, type);

    return in;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<record> records(n);

    for(auto & i : records)
        cin >> i;

    vector<vector<record> > dp(n+1, vector<record>(3, record(DAY-1) ) );

    dp[0][0] = dp[0][1] = dp[0][2] = record(0);


    for(int i = 1; i<=n; i++)
    {

        if(records[i-1]._type == "?")
        {
            dp[i][0] = dp[i-1][1];
            if(i!=1)
            {
                dp[i][1] = min(dp[i-1][2] + (records[i-1] - records[i-2]),
                               dp[i-1][0] + (records[i-1] - records[i-2]));

                dp[i][2] = min(dp[i-1][2] + (records[i-1] - records[i-2]),
                               dp[i-1][0] + (records[i-1] - records[i-2]));
            }
        }
        else
        if(records[i-1]._type == "#")
        {
            dp[i][2] = min(dp[i-1][2] + (records[i-1] - records[i-2]),
                           dp[i-1][0] + (records[i-1] - records[i-2]));

        }
        else
        if(records[i-1]._type == "<")
        {
            dp[i][0] = dp[i-1][1];
        }
        else
        {
            dp[i][1] = min(dp[i-1][2] + (records[i-1] - records[i-2]),
                           dp[i-1][0] + (records[i-1] - records[i-2]));
        }



    }

    cout << dp[n][1]._time;

    return 0;
}
