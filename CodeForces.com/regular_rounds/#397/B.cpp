#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string s;

    int last = 'a' - 1;

    cin >> s;
    for(auto i : s)
    {
        if(i > last && last+1!=i)
        {
            cout <<"NO";
            return 0;
        }
        else
        {
            last = max((int)i, last);
        }

    }
    cout << "YES";

    return 0;
}
