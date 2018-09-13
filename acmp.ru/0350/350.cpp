#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    sort(s.begin(),s.end());
    do
    {
        cout << s << '\n';
    }
    while(next_permutation(s.begin(), s.end()));

    return 0;
}
