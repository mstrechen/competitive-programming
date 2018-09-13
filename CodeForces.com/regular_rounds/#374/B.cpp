#include<iostream>
#include<algorithm>

using namespace std;


bool comp(string a, string b)
{
    return a.size()<b.size();
}

string a[200];

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    string s;
    cin >> n >> k;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    a[n].assign(200,'a');
    sort(a,a+n, comp);
    cin >> s;

    int minTime = 0, maxTime = 0;
    int count = 0, currTime = 0;
    for(int i = 0; i<=n&&maxTime==0; i++)
    {
        count++;
        currTime++;
        if(minTime==0&&a[i].size()==s.size())
        {
            minTime = currTime;
        }
        if(maxTime==0&&a[i+1].size()>s.size())
        {
            maxTime = currTime;
        }

        if(count>=k)
        {
            currTime+=5;
            count = 0;
        }


    }
    cout << minTime << ' ' << maxTime;
    return 0;
}
