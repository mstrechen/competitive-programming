#include<iostream>
#include<algorithm>

using namespace std;

pair<int,int> a[6];
int main()
{
    for(int i = 0; i<6; i++)
        cin >> a[i].first >> a[i].second;
    for(int i = 0; i<6; i++)
        if(a[i].first>a[i].second)
            swap(a[i].first, a[i].second);
    sort(a,a+6);
    if(a[0]==a[1]&&a[2]==a[3]&&a[4]==a[5])
    {
        if(a[0].first==a[2].first)
        {
            if((a[0].second==a[4].first&&a[2].second==a[4].second)||
               (a[0].second==a[4].second&&a[2].second==a[4].first))
            {
                cout << "POSSIBLE";
                return 0;
            }
        }
        if(a[0].first==a[2].second)
        {
            if((a[0].second==a[4].first&&a[2].first==a[4].second)||
               (a[0].second==a[4].second&&a[2].first==a[4].first))
            {
                cout << "POSSIBLE";
                return 0;
            }

        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}
