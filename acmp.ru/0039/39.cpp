#include<iostream>
#include<vector>

using namespace std;

int a[1000000];
vector<int> days;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>> n;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    days.push_back(n-1);
    for(int i = n-2; i>=0; i--)
    {
        if(a[i]>a[days[days.size()-1]])
            days.push_back(i);
    }
    int k = -1;
    long long answer = 0;
    for(int i = days.size()-1; i>=0; i--)
    {
        answer+=(days[i]-k)*a[days[i]];
        k = days[i];
    }
    cout << answer;
    return 0;
}
