#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int> > rectangles(n);
    for(auto & i : rectangles)
        cin >> i.first >> i.second;

    sort(rectangles.begin(), rectangles.end(), greater<pair<int,int> >());

    long long ans = 0;
    int currentY = 0;

    for(auto & i : rectangles)
    {
        if(currentY<i.second)
        {
            ans+=(i.second-currentY)*1LL*i.first;
            currentY = i.second;
        }
    }

    cout << ans;


    return 0;
}
