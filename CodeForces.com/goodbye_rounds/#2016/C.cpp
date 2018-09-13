#include<iostream>
#include<set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >>  n;

    set<int> div1, div2;

    int cur = 0;
    int dX, div;

    for(int i = 0; i<n; i++)
    {
        cin >> dX >> div;

        if(div == 1)
        {
            div1.insert(cur);
        }
        else
        {
            div2.insert(cur);
        }
        cur+=dX;
    }



    if(div2.empty())
    {
        cout << "Infinity";
        return 0;
    }
    if(div1.empty())
    {
        cout << 1899 - *div2.rbegin() + cur;
        return 0;
    }

    if(*div2.rbegin()>=*div1.begin())
    {
        cout << "Impossible";
        return 0;
    }

    cout << 1899 - *div2.rbegin() + cur;

    return 0;
}
