#include<iostream>
#include<algorithm>

using namespace std;

const int oo = 2000000000;

pair<int,int> notes[100500];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;


    for(int i = 0; i<n; i++)
    {
        cin >> notes[i].first >> notes[i].second;
    }

    bool needASort = 0;

    for(int i = 1; i<n; i++)
        needASort|=(notes[i-1].first>notes[i].first);

    if(needASort)
        sort(notes, notes+n);

    int ans = 0;
    int prevHigh = +oo;
    int prevTime = 0;
    int currLen = 0;

    for(int i = 0; i<n; i++)
    {
        if(prevHigh < notes[i].second)
            currLen+=notes[i].first - prevTime;
        else
        {
            ans = max(ans, currLen);
            currLen = 0;
        }
        prevHigh = notes[i].second;
        prevTime = notes[i].first;
    }

    ans = max(ans, currLen);

    cout << ans;

    return 0;
}
