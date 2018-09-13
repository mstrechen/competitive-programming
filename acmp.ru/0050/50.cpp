#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    set<string> cycle_shift;

    cin >> a >> b;

    for(int i = 0; i<b.size(); i++)
    {
        cycle_shift.insert(b);
        reverse(b.begin(), b.end());
        reverse(b.begin()+1, b.end());
    }
    int ans = 0;
    for(int i = 0; i<a.size()-b.size()+1; i++)
    {
        ans+=cycle_shift.count(string(a.begin()+i, a.begin()+i+b.size()) );
    }
    cout << ans;

    return 0;
}
